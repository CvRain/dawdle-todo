//
// Created by cvrain on 24-6-10.
//

#ifndef DAWDLE_TODO_DATABASE_SERVICE_HPP
#define DAWDLE_TODO_DATABASE_SERVICE_HPP

#include <string>
#include <string_view>
#include <sqlite_orm/sqlite_orm.h>

#include <model/todo_group.hpp>

namespace Service {
    inline auto init_storage(const std::string_view &db_path) {
        using namespace sqlite_orm;
        auto storage = make_storage(db_path.data(),
                                    make_table("COMPANY",
                                               make_column("id", &Model::TodoGroup::id, primary_key()),
                                               make_column("name", &Model::TodoGroup::name),
                                               make_column("times", &Model::TodoGroup::times),
                                               make_column("category", &Model::TodoGroup::category),
                                               make_column("create_time", &Model::TodoGroup::create_time),
                                               make_column("finish_time", &Model::TodoGroup::finish_time)));
        return storage;
    }
    using Storage = decltype(init_storage(""));


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
        std::unique_ptr<Storage> storage;
    };

} // Service

#endif //DAWDLE_TODO_DATABASE_SERVICE_HPP
