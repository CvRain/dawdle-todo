//
// Created by cvrain on 24-5-8.
//

#include "singleton_database.hpp"

#include <filesystem>
#include <iostream>
#include <leveldb/write_batch.h>

SingletonDatabase &SingletonDatabase::get_instance() {
    static SingletonDatabase instance{};
    return instance;
}

void SingletonDatabase::initialize(const std::string_view &db_path) {
    //检查db_path所在的文件夹是否存在，没有则新建
    if (!std::filesystem::exists(db_path)) {
        std::filesystem::create_directories(db_path);
    }
    //连接数据库，没有数据库则创建
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::DB *db = database.get();
    const auto status = leveldb::DB::Open(options, db_path.data(), &db);
    //check status
    if (!status.ok()) {
        throw std::runtime_error(status.ToString());
    }
}

std::vector<std::string> SingletonDatabase::get_all_key() {
    auto iter = database->NewIterator(leveldb::ReadOptions());
    std::vector<std::string> keys;
    for (iter->SeekToFirst(); iter->Valid(); iter->Next()) {
        keys.push_back(iter->key().ToString());
    }
    return keys;
}

std::vector<std::string> SingletonDatabase::get_all_value() {
    auto iter = database->NewIterator(leveldb::ReadOptions());
    std::vector<std::string> values;
    for (iter->SeekToFirst(); iter->Valid(); iter->Next()) {
        values.push_back(iter->value().ToString());
    }
    return values;
}

std::optional<std::string> SingletonDatabase::get_value(const std::string_view &key) {
    std::string value;
    const auto status = database->Get(leveldb::ReadOptions(), key.data(), &value);
    if (status.ok()) {
        return value;
    } else {
        return std::nullopt;
    }
}

leveldb::Status SingletonDatabase::put(const std::string_view &key, const std::string_view &value) {
    const auto status = database->Put(leveldb::WriteOptions(), key.data(), value.data());
    return status;
}

leveldb::Status SingletonDatabase::remove(const std::string_view &key) {
    const auto result = database->Delete(leveldb::WriteOptions(), key.data());
    return result;
}

leveldb::Status SingletonDatabase::update(const std::string_view &key, const std::string_view &value) {
    auto find_value = get_value(key);
    if (!find_value.has_value()) {
        return {};
    }
    leveldb::WriteBatch batch;
    batch.Delete(key.data());
    batch.Put(key.data(), value.data());
    return database->Write(leveldb::WriteOptions(), &batch);
}
