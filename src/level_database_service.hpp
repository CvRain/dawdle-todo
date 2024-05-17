//
// Created by cvrain on 24-5-8.
//

#ifndef DAWDLE_TODO_LEVEL_DATABASE_SERVICE_HPP
#define DAWDLE_TODO_LEVEL_DATABASE_SERVICE_HPP

#include <string>
#include <memory>
#include <vector>
#include <mutex>
#include <optional>
#include <leveldb/db.h>

class LevelDatabase {
public:
    static LevelDatabase& get_instance(const std::string_view& db_path = "./db/todo_db");
    std::vector<std::string> get_all_key();
    std::vector<std::string> get_all_value();
    std::optional<std::string> get_value(const std::string_view& key);
    leveldb::Status put(const std::string_view& key, const std::string_view& value);
    leveldb::Status remove(const std::string_view& key);
    leveldb::Status update(const std::string_view& key, const std::string_view& value);
    uint size();

    LevelDatabase(const LevelDatabase&) = delete;
    LevelDatabase& operator=(const LevelDatabase&) = delete;
private:
    explicit LevelDatabase(const std::string_view& db_path);
    ~LevelDatabase();

    static std::once_flag flag;
    static std::unique_ptr<leveldb::DB> database;
    static std::mutex mutex;
};


#endif //DAWDLE_TODO_LEVEL_DATABASE_SERVICE_HPP
