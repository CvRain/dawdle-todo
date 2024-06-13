//
// Created by cvrain on 24-6-10.
//

#ifndef DAWDLE_TODO_DATABASE_SERVICE_HPP
#define DAWDLE_TODO_DATABASE_SERVICE_HPP

#include <string>
#include <string_view>
#include <filesystem>
#include <sqlite_orm/sqlite_orm.h>

#include <model/todo_group.hpp>

namespace Service {
    inline auto init_storage(const std::string_view &db_path = "./db/dawdle.sqlite") {
        using namespace sqlite_orm;
        //check directory is existed or create one
        if (!std::filesystem::exists(db_path)) {
            std::filesystem::create_directories(db_path.substr(0, db_path.find_last_of('/')));
        }

        //init sqlite database
        auto storage = make_storage(db_path.data(),
                                    make_table("todo_group",
                                               make_column("id", &Model::TodoGroup::id),
                                               make_column("name", &Model::TodoGroup::name),
                                               make_column("times", &Model::TodoGroup::times),
                                               make_column("category", &Model::TodoGroup::category),
                                               make_column("create_time", &Model::TodoGroup::create_time),
                                               make_column("finish_time", &Model::TodoGroup::finish_time)));
        return storage;
    }
    using Storage = decltype(init_storage(""));
    using StoragePtr =  std::unique_ptr<Storage>;

    //singleton database service
    class DatabaseService final {
    public:
        static DatabaseService &get_instance(const std::string_view& db_path = "./db/dawdle.sqlite");

        DatabaseService(const DatabaseService &) = delete;

        DatabaseService &operator=(const DatabaseService &) = delete;

        void add_one(const Model::TodoGroup &todo_group);

        void print_all();

    private:
        explicit DatabaseService(const std::string_view& db_path = "./db/dawdle.sqlite");

        ~DatabaseService();

    private:
        static DatabaseService *instance;
        StoragePtr storage;
    };

} // Service

#endif //DAWDLE_TODO_DATABASE_SERVICE_HPP
