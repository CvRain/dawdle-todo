#include <filesystem>
#include <mutex>
#include <spdlog/spdlog.h>
#include <duckdb.hpp>
#include <string_view>

namespace Service{
    class DuckDatabase{
    public:
        [[nodiscard]] DuckDatabase& get_instance(const std::string_view& db_path = "./db/duck.db");
        DuckDatabase(const DuckDatabase&) = delete;
        DuckDatabase(DuckDatabase&&) = delete;
        DuckDatabase operator=(const DuckDatabase&) = delete;
    private:
        explicit DuckDatabase(const std::string_view& db_path = "./db/duck.db");
        ~DuckDatabase() = default;
    private:
        static std::once_flag flag;
        static std::mutex mutex;
        duckdb::DuckDB database;
        duckdb::Connection connection;
    };
}
