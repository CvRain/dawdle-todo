//
// Created by cvrain on 24-6-13.
//

#include "todo_group_table.hpp"

namespace Service {
    std::string TodoGroupTable::add_one(const Model::TodoGroup &todo_group) {
        spdlog::info("TodoGroupTable::add_one::todo_group: {}", todo_group.id);
        try {
            Service::DatabaseService::get_instance().get_storage()->insert(todo_group);
        } catch (const std::system_error &exception) {
            spdlog::error("TodoGroupTable::create_one::system_error: {}", exception.what());
        } catch (const std::exception &exception) {
            spdlog::error("TodoGroupTable::create_one::unknown_error: {}", exception.what());
        }
        return todo_group.id;
    }

    void TodoGroupTable::print_all() {
        spdlog::info("TodoGroupTable::print_all");
        const auto all_todo_groups = Service::DatabaseService::get_instance().get_storage()->get_all<Model::TodoGroup>();
        for (const auto &todo_group : all_todo_groups) {
            spdlog::info(Service::DatabaseService::get_instance().get_storage()->dump(todo_group));
        }
    }


}