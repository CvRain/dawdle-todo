//
// Created by cvrain on 24-5-8.
//

#ifndef DAWDLE_TODO_SINGLETON_DATABASE_HPP
#define DAWDLE_TODO_SINGLETON_DATABASE_HPP

#include <string>
#include <memory>
#include <vector>
#include <optional>
#include <leveldb/db.h>

class SingletonDatabase {
public:
    [[nodiscard]] static SingletonDatabase& get_instance();
    void initialize(const std::string_view& db_path = "./db/todo_db");
    std::vector<std::string> get_all_key();
    std::vector<std::string> get_all_value();
    std::optional<std::string> get_value(const std::string_view& key);
    leveldb::Status put(const std::string_view& key, const std::string_view& value);
    leveldb::Status remove(const std::string_view& key);
    leveldb::Status update(const std::string_view& key, const std::string_view& value);
    uint size();
    SingletonDatabase(const SingletonDatabase&) = delete;
    SingletonDatabase& operator=(const SingletonDatabase&) = delete;
private:
    SingletonDatabase() = default;
    ~SingletonDatabase() = default;
    std::unique_ptr<leveldb::DB> database;
};


#endif //DAWDLE_TODO_SINGLETON_DATABASE_HPP
