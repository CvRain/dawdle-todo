//
// Created by cvrain on 24-5-8.
//

#ifndef DAWDLE_TODO_TODO_MANAGER_HPP
#define DAWDLE_TODO_TODO_MANAGER_HPP

#include <string>
#include <string_view>
#include "singleton_database.hpp"
#include "todo_structure.h"

class TodoManager {
public:
    explicit TodoManager() = default;
    std::vector<std::string> get_all_group_name();
    std::vector<std::string> get_all_todo_name();
private:
    TodoStructure::TodoInfoValue todo_head_serialization(const std::string_view& json_string);
    std::string todo_head_deserialization(const TodoStructure::TodoInfoValue& todo_info_value);
};


#endif //DAWDLE_TODO_TODO_MANAGER_HPP
