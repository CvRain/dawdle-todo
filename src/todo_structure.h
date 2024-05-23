//
// Created by cvrain on 24-5-9.
//

#ifndef DAWDLE_TODO_TODO_STRUCTURE_H
#define DAWDLE_TODO_TODO_STRUCTURE_H

#include <string>
#include <string_view>
#include <map>
#include "simple_id.hpp"

namespace TodoStructure {
    enum class TodoCategory {
        Cycle,
        Daily,
        Once,
        Property
    };
    struct TodoGroupInfo {
        std::string group_id;
        std::string group_name;
        std::string finish_time;
        std::string category;
    };

    inline std::map<TodoCategory, std::string> TodoCategoryAsMap(){
        std::map<TodoCategory, std::string> category_map{};
        category_map[TodoCategory::Cycle] = "cycle";
        category_map[TodoCategory::Daily] = "daily";
        category_map[TodoCategory::Once] = "once";
        category_map[TodoCategory::Property] = "property";
        return category_map;
    }

    struct QueryStructure{
        std::string create_table_todo_group;
        std::string create_table_todo_item;
        std::string new_todo_group;
        std::string todo_group_all;
        std::string todo_group_count;
        std::string todo_group_overview;
        std::string delete_todo_group;

        inline std::string get_delete_group_query(const std::string_view& group_id) const{
            //delete from todo_group where id = '{}' 将{}替换为group_id
            if(group_id.empty()) return "";
            return std::string(delete_todo_group).replace(delete_todo_group.find("{}"), 2, group_id);
        }

        inline std::string get_new_group_query(const std::string_view& group_name, const std::string_view& category){
            //insert into todo_group(id, name, times, category, create_time, finish_time) values ('{}', '{}', 0, '{}', '{}', '2021-01-01 00:00:00');
            const auto id = Tool::Id::SimpleId::generate_id();
            const auto create_time = Tool::Id::SimpleId::local_timestamp_string();
            return std::string(new_todo_group).replace(new_todo_group.find("{}"), 2, id)
                    .replace(new_todo_group.find("{}"), 2, group_name)
                    .replace(new_todo_group.find("{}"), 2, "0")
                    .replace(new_todo_group.find("{}"), 2, category)
                    .replace(new_todo_group.find("{}"), 2, create_time);
        }
    };
}

#endif //DAWDLE_TODO_TODO_STRUCTURE_H
