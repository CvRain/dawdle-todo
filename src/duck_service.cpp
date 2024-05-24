//
// Created by cvrain on 24-5-17.
//

#include "duck_service.hpp"
#include <filesystem>

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

    std::vector<TodoStructure::TodoGroupInfo> DuckDatabase::get_group_info() {
        const auto result = connection.Query(query_reader->get_query_structure().todo_group_overview);
        if(!result){
            spdlog::error("get group info error");
            return {};
        }
        const auto row_count = result->Collection().Count();
        const auto column_count = result->types.size();
        auto data = std::vector<TodoStructure::TodoGroupInfo>{};
        for(duckdb::idx_t row = 0; row < row_count; ++row){
            auto group_info = TodoStructure::TodoGroupInfo{
              .group_id = result->GetValue(0, row).GetValue<std::string>(),
              .group_name = result->GetValue(1, row).GetValue<std::string>(),
              .finish_time = result->GetValue(2, row).GetValue<std::string>(),
              .category = result->GetValue(3, row).GetValue<std::string>(),
            };

            spdlog::info("get group info: id::{} name::{} category::{}",group_info.group_id, group_info.group_name, group_info.category);

            data.emplace_back(group_info);
        }
        return data;
    }

    void DuckDatabase::delete_one_group(const std::string_view &group_id) {
        if(const auto query_str = query_reader->get_query_structure().get_delete_group_query(group_id); !query_str.empty()){
            const auto result = connection.Query(query_str);
            if(result){
                spdlog::info("delete group {} success", group_id);
            }else{
                spdlog::error("delete group {} error", group_id);
            }
        }
    }

    void DuckDatabase::add_one_group(const std::string_view &group_name, const std::string_view &group_category) {
        spdlog::info("DuckDatabase::add_one_group");
        spdlog::info("add group {}", group_name);
        if(const auto query_str = query_reader->get_query_structure().get_new_group_query(group_name, group_category); !query_str.empty()){
            spdlog::info("{}", query_str);
            const auto result = connection.Query(query_str);
            if(result){
                spdlog::info("add group {} success", group_name);
            }else{
                spdlog::error("add group {} error", group_name);
            }
        }
    }
}
