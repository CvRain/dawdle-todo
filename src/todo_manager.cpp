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

    std::optional<TodoStructure::TodoGroupInfo>
    TodoManager::todo_head_serialization(const std::string_view &json_string) {
        Json::Value root;
        Json::Reader reader;
        spdlog::info("load {}", json_string);
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
        spdlog::info("new todo group: {} {}", group_text.toLocal8Bit().toStdString(),
                     category_text.toLocal8Bit().toStdString());
        const auto todo_head = TodoStructure::TodoGroupInfo{
                .group_name = group_text.toStdString(),
                .group_id = Tool::Id::SimpleId::generate_id(),
                .category = category_text.toStdString()
        };
        spdlog::info("generate id: {}", todo_head.group_id);
        const auto json_todo_head = todo_head_deserialization(todo_head);
        database_instance.put(json_todo_head, std::string{});
    }

    std::vector<TodoStructure::TodoGroupInfo> TodoManager::get_all_todo_group() {
        spdlog::info("enter TodoManager::get_all_todo_group()");
        const auto group_data = database_instance.get_all_key();
        std::vector<TodoStructure::TodoGroupInfo> info_groups{database_instance.size()};
        for (const auto &group_data_value: group_data) {
            const auto todo_head = todo_head_serialization(group_data_value);
            if (!todo_head.has_value()) {
                break;
            }
            spdlog::info("load json: {}", group_data_value);
            info_groups.emplace_back(todo_head.value());
        }
        return info_groups;
    }

}