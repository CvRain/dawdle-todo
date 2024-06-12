//
// Created by cvrain on 24-6-10.
//

#include "database_service.hpp"

#include <spdlog/spdlog.h>

namespace Service {
    Service::DatabaseService *DatabaseService::instance = nullptr;

    DatabaseService::DatabaseService(const std::string_view &db_path) {
        spdlog::info("DatabaseService::DatabaseService()");
        storage = std::make_unique<Storage>(init_storage(db_path.data()));
        storage->sync_schema();
    }

    DatabaseService &DatabaseService::get_instance(const std::string_view &db_path) {
        if (instance == nullptr) {
            spdlog::info("DatabaseService::get_instance()");
            instance = new DatabaseService(db_path);
        }
        return *instance;
    }

    DatabaseService::~DatabaseService() {
        delete instance;
        instance = nullptr;
    }

    void DatabaseService::add_one(const Model::TodoGroup &todo_group) {
        storage->replace(todo_group);
    }

    void DatabaseService::print_all() {
        for(auto& one_group : storage->iterate<Model::TodoGroup>()){
            spdlog::info(storage->dump(one_group));
        }
    }


} // Service