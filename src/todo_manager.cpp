//
// Created by cvrain on 24-5-8.
//

#include "todo_manager.hpp"
#include <json/json.h>

TodoManager::TodoManager(QObject *object) : QObject(object) {

}

TodoStructure::TodoGroupInfo TodoManager::todo_head_serialization(const std::string_view &json_string) {
    

    return TodoStructure::TodoGroupInfo();
}

std::string TodoManager::todo_head_deserialization(const TodoStructure::TodoGroupInfo &todo_info_value) {
    return std::string();
}

void TodoManager::new_todo_group(const QString &group_text, const QString &category_text) {

}

