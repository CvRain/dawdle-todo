//
// Created by cvrain on 24-5-8.
//

#include "todo_manager.hpp"
#include <json/json.h>

TodoStructure::TodoInfoValue TodoManager::todo_head_serialization(const std::string_view &json_string) {
    

    return TodoStructure::TodoInfoValue();
}

std::string TodoManager::todo_head_deserialization(const TodoStructure::TodoInfoValue &todo_info_value) {
    return std::string();
}
