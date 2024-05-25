//
// Created by cvrain on 24-5-8.
//

#include "todo_manager.hpp"
#include "simple_id.hpp"
#include "duck_service.hpp"
#include <json/json.h>
#include <spdlog/spdlog.h>

namespace Controller {
    TodoManager* TodoManager::instance = nullptr;

    TodoManager &TodoManager::get_instance() {
        if (!instance) {
            instance = new TodoManager();
        }
        return *instance;
    }

    TodoManager::TodoManager(QObject *object) : QObject(object) {
        spdlog::info("todo manager created::{}", (typeid(*this)).name());
        auto &db_instance = Service::DuckDatabase::get_instance();
    }

    std::optional<TodoStructure::TodoGroupInfo>
    TodoManager::todo_head_serialization(const std::string_view &json_string) {
        Json::Value root;
        Json::Reader reader;
        TodoStructure::TodoGroupInfo todo_info_value{};
        if (!reader.parse(json_string.data(), root)) {
            spdlog::error("json parse error: {}", reader.getFormattedErrorMessages());
            return std::nullopt;
        }
        if (!root.isMember("group-name") || !root.isMember("group-id") || !root.isMember("category")) {
            return std::nullopt;
        }
        try {
            todo_info_value.group_name = root["group-name"].asString();
            todo_info_value.group_id = root["group-id"].asString();
            todo_info_value.category = root["category"].asString();
        } catch (const std::exception &e) {
            spdlog::error("{}", e.what());
        }
        return todo_info_value;
    }

    std::string TodoManager::todo_head_deserialization(const TodoStructure::TodoGroupInfo &todo_info_value) {
        Json::Value root;
        try {
            root["group-name"] = Json::Value(todo_info_value.group_name);
            root["group-id"] = Json::Value(todo_info_value.group_id);
            root["category"] = Json::Value(todo_info_value.category);
        } catch (const std::exception &e) {
            spdlog::error("{}", e.what());
        }
        const auto result = Json::FastWriter().write(root);
        return result;
    }

    void TodoManager::new_todo_group(const QString &group_text, const QString &category_text) {
        spdlog::info("TodoManager::new_todo_group");
        TodoStructure::TodoGroupInfo newGroup;
        newGroup.group_id = Tool::Id::SimpleId::generate_id();
        newGroup.group_name = group_text.toLocal8Bit().toStdString();
        newGroup.category = category_text.toLocal8Bit().toStdString();
        newGroup.finish_time = "1970-01-01 00:00:00";

        Service::DuckDatabase::get_instance().add_one_group(newGroup);

        emit newGroupAdded(newGroup);
    }

    void TodoManager::delete_todo_group(const QString &group_id) {
        spdlog::info("TodoManager::delete_todo_group");
        Service::DuckDatabase::get_instance().delete_one_group(group_id.toLocal8Bit().toStdString());
    }
}