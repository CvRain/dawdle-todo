//
// Created by cvrain on 24-5-8.
//

#include "level_database_service.hpp"

#include <filesystem>
#include <iostream>
#include <leveldb/write_batch.h>
#include <spdlog/spdlog.h>

std::once_flag LevelDatabase::flag;
std::unique_ptr<leveldb::DB> LevelDatabase::database = nullptr;
std::mutex LevelDatabase::mutex;

std::vector<std::string> LevelDatabase::get_all_key() {
    spdlog::info("enter LevelDatabase::get_all_key()");
    try {
        const auto iter = database->NewIterator(leveldb::ReadOptions());
        if(iter == nullptr){
            spdlog::info("iter is nullptr");
            return {};
        }
        if (!iter->status().ok()) {
            throw std::runtime_error(iter->status().ToString());
        }
        std::vector<std::string> keys;
        for (iter->SeekToFirst(); iter->Valid(); iter->Next()) {
            spdlog::info("key: {}", iter->key().ToString());
            keys.push_back(iter->key().ToString());
        }
        return keys;
    }catch(const std::exception& exception) {
        spdlog::error("get all key error: {}", exception.what());
    }
    return {};
}

std::vector<std::string> LevelDatabase::get_all_value() {
    auto iter = database->NewIterator(leveldb::ReadOptions());
    std::vector<std::string> values;
    for (iter->SeekToFirst(); iter->Valid(); iter->Next()) {
        values.push_back(iter->value().ToString());
    }
    return values;
}

std::optional<std::string> LevelDatabase::get_value(const std::string_view &key) {
    std::string value;
    const auto status = database->Get(leveldb::ReadOptions(), key.data(), &value);
    if (status.ok()) {
        return value;
    } else {
        return std::nullopt;
    }
}

leveldb::Status LevelDatabase::put(const std::string_view &key, const std::string_view &value) {
    spdlog::info("put key: {} value: {}", key.data(), value.data());
    if(key.empty()){
        return {};
    }
    const auto status = database->Put(leveldb::WriteOptions(), key.data(), value.data());
    return status;
}

leveldb::Status LevelDatabase::remove(const std::string_view &key) {
    const auto result = database->Delete(leveldb::WriteOptions(), key.data());
    return result;
}

leveldb::Status LevelDatabase::update(const std::string_view &key, const std::string_view &value) {
    auto find_value = get_value(key);
    if (!find_value.has_value()) {
        return {};
    }
    leveldb::WriteBatch batch;
    batch.Delete(key.data());
    batch.Put(key.data(), value.data());
    return database->Write(leveldb::WriteOptions(), &batch);
}

uint LevelDatabase::size() {
    return get_all_key().size();
}

LevelDatabase &LevelDatabase::get_instance(const std::string_view &db_path) {
    static LevelDatabase instance(db_path);
    return instance;
}

LevelDatabase::LevelDatabase(const std::string_view& db_path) {
    std::call_once(flag, [&]() {
        std::lock_guard<std::mutex> lock(mutex);
        if (!std::filesystem::exists(db_path)) {
            spdlog::info("create database folder {}", db_path.data());
            std::filesystem::create_directories(db_path);
        }
        leveldb::Options options;
        options.create_if_missing = true;
        leveldb::DB* db_ptr = nullptr;
        const auto status = leveldb::DB::Open(options, db_path.data(), &db_ptr);
        if (!status.ok()) {
            throw std::runtime_error(status.ToString());
        }
        database.reset(db_ptr);
        spdlog::info("success to link database");
    });
}

LevelDatabase::~LevelDatabase() {
    database.reset();
}
