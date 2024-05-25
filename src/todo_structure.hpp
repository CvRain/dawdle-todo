//
// Created by cvrain on 24-5-9.
//

#ifndef DAWDLE_TODO_TODO_STRUCTURE_HPP
#define DAWDLE_TODO_TODO_STRUCTURE_HPP

#include <string>
#include <string_view>
#include <map>

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

    class QueryStructure{
    public:
        std::string create_table_todo_group;
        std::string create_table_todo_item;
        std::string new_todo_group;
        std::string todo_group_all;
        std::string todo_group_count;
        std::string todo_group_overview;
        std::string delete_todo_group;

        [[nodiscard]] std::string get_delete_group_query(const std::string_view& group_id) const;
        [[nodiscard]] std::string get_new_group_query(const std::string_view& group_name, const std::string_view& category) const;
        [[nodiscard]] std::string get_new_group_query(const TodoStructure::TodoGroupInfo &group_info) const;
    };
}

#endif //DAWDLE_TODO_TODO_STRUCTURE_HPP
