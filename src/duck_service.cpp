//
// Created by cvrain on 24-5-17.
//

#include "duck_service.hpp"

namespace Service {
    std::once_flag DuckDatabase::flag{};
    std::mutex DuckDatabase::mutex{};

    DuckDatabase::DuckDatabase(const std::string_view &db_path)
            : database(db_path.data()), connection(database),
              query_reader(std::make_unique<DbQueryReader>()) {
        database = duckdb::DuckDB{db_path.data()};
        connection = duckdb::Connection{database};
        spdlog::info("success to link duckDB");

        connection.Query(query_reader->get_query_structure().create_table_todo_group);
        spdlog::info("{}",query_reader->get_query_structure().create_table_todo_item );
        connection.Query(query_reader->get_query_structure().create_table_todo_item);

        spdlog::info("success to link database");

    }

    DuckDatabase &DuckDatabase::get_instance(const std::string_view &db_path) {
        std::call_once(flag, [&]() {
            spdlog::info("start to link duckDB");
            std::lock_guard<std::mutex> lock(mutex);
            //判断是否存在数据库文件
            //判断数据库文件上层文件夹是否存在，如果没有则创建
            if (!std::filesystem::exists(db_path)) {
                spdlog::info("create database file");
                std::filesystem::path db_path_path{db_path};
                std::filesystem::path db_path_parent_path{db_path_path.parent_path()};
                if (!std::filesystem::exists(db_path_parent_path)) {
                    std::filesystem::create_directories(db_path_parent_path);
                }
            }
        });
        static DuckDatabase instance{db_path};
        return instance;
    }

    int DuckDatabase::get_group_count() {
        //"select count(todo_group.id) from todo_group;"
        const auto result = connection.Query(query_reader->get_query_structure().todo_group_count);
        if(!result){
            spdlog::error("get group count error");
            return -1;
        }
        const auto row_count = result->Collection().Count();
        if(row_count == 0){
            spdlog::error("get group count error");
            return -1;
        }
        const auto value = result->GetValue(0,0);
        const auto count = value.GetValue<int64_t>();
        spdlog::info("get group count:{}",count);
        return static_cast<int>(count);
    }
}