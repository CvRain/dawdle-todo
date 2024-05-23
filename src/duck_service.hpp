#pragma once

#include <filesystem>
#include <mutex>
#include <spdlog/spdlog.h>
#include <duckdb.hpp>
#include <string_view>
#include <vector>

#include "db_query_reader.hpp"


namespace Service {
    class DuckDatabase {
    public:
        [[nodiscard]] static DuckDatabase &get_instance(const std::string_view &db_path = "./db/duck.db");

        DuckDatabase(const DuckDatabase &) = delete;

        DuckDatabase(DuckDatabase &&) = delete;

        DuckDatabase operator=(const DuckDatabase &) = delete;

        int get_group_count();

        std::vector<TodoStructure::TodoGroupInfo> get_group_info();

        void delete_one_group(const std::string_view& group_id);

        void add_one_group(const std::string_view& group_name, const std::string_view& group_category);

    private:
        explicit DuckDatabase(const std::string_view &db_path = "./db/duck.db");

        ~DuckDatabase() = default;

    private:
        static std::once_flag flag;
        static std::mutex mutex;
        duckdb::DuckDB database;
        duckdb::Connection connection;
        std::unique_ptr<DbQueryReader> query_reader;
    };
}
