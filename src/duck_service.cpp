//
// Created by cvrain on 24-5-17.
//

#include "duck_service.hpp"

namespace Service {
    std::once_flag DuckDatabase::flag{};
    std::mutex DuckDatabase::mutex{};

    DuckDatabase::DuckDatabase(const std::string_view &db_path)
            : database(nullptr), connection(database) { //下下之策，但是没想到为了实现单例模式怎么初始化。
        std::call_once(flag, [&]() {
            std::lock_guard<std::mutex> lock(mutex);
            if (!std::filesystem::exists(db_path)) {
                spdlog::info("create database folder {}", db_path.data());
                std::filesystem::create_directories(db_path);
            }
            database = duckdb::DuckDB{db_path.data()};
            connection = duckdb::Connection{database};
            spdlog::info("success to link database");
        });
    }

    DuckDatabase &DuckDatabase::get_instance(const std::string_view &db_path) {
        static DuckDatabase instance{db_path};
        return instance;
    }
}