//
// Created by cvrain on 24-5-9.
//

#ifndef DAWDLE_TODO_TODO_STRUCTURE_H
#define DAWDLE_TODO_TODO_STRUCTURE_H

#include <string>
#include <map>

namespace TodoStructure {
    enum class TodoCategory {
        Cycle,
        Daily,
        Once,
        Property
    };
    struct TodoGroupInfo {
        std::string group_name;
        std::string group_id;
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
        std::string todo_group_all;
        std::string todo_group_count;
    };
}

#endif //DAWDLE_TODO_TODO_STRUCTURE_H
