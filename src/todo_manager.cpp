//
// Created by cvrain on 24-5-8.
//

#include "todo_manager.hpp"
#include "simple_id.hpp"
#include <json/json.h>
#include <spdlog/spdlog.h>

namespace Controller {
    TodoManager::TodoManager(QObject *object) : QObject(object) {
        spdlog::info("todo manager created");
    }

    TodoStructure::TodoGroupInfo TodoManager::todo_head_serialization(const std::string_view &json_string) {


        return TodoStructure::TodoGroupInfo();
    }

    std::string TodoManager::todo_head_deserialization(const TodoStructure::TodoGroupInfo &todo_info_value) {
        Json::Value root;
        try {
            root["group-name"] = todo_info_value.group_name;
            root["group-id"] = todo_info_value.group_id;
            root["category"] = todo_info_value.category;
            spdlog::info("{}", root.asString());
        } catch (const std::exception &e) {
            spdlog::error("{}", e.what());
        }
        return root.asString();
    }

    void TodoManager::new_todo_group(const QString &group_text, const QString &category_text) {
        spdlog::info("new todo group: {} {}", group_text.toLocal8Bit().toStdString(),
                     category_text.toLocal8Bit().toStdString());
        const auto todo_head = TodoStructure::TodoGroupInfo{
                .group_name = group_text.toStdString(),
                .group_id = Tool::Id::SimpleId::generate_id(),
                .category = category_text.toStdString()
        };
        spdlog::info("generate id: {}", todo_head.group_id);
        const auto json_todo_head = todo_head_deserialization(todo_head);
        SingletonDatabase::get_instance().put(json_todo_head, {});
    }

}