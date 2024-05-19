//
// Created by cvrain on 24-5-17.
//

#include "db_query_reader.hpp"
#include "spdlog/spdlog.h"

#include <json/json.h>
#include <QFileInfo>

DbQueryReader::DbQueryReader() {
    const auto all_str = read_file();
    init_query_structure(all_str);
}

std::string DbQueryReader::read_file() {
    const QString file_path{":/sql/sql/query.json"};
    //判断文件是否存在
    if (!QFileInfo::exists(file_path)) {
        spdlog::error("file not exist");
        return {};
    }

    QFile file{file_path};
    if (!file.open(QIODevice::ReadOnly)) {
        spdlog::error("open file failed");
        return {};
    }
    const auto all_data = file.readAll();
    const auto all_str = all_data.toStdString();
    file.close();
    return all_str;
}

void DbQueryReader::init_query_structure(const std::string &json_string) {
    Json::Value root;
    Json::Reader reader;
    if (!reader.parse(json_string, root)) {
        spdlog::error("parse json failed");
        return;
    }
    query_structure.create_table_todo_group = root["create"]["table_todo_group"].asString();
    query_structure.create_table_todo_item = root["create"]["table_todo_item"].asString();
    query_structure.todo_group_all = root["retrieve"]["todo_group_all"].asString();
    query_structure.todo_group_count = root["retrieve"]["todo_group_count"].asString();
}

TodoStructure::QueryStructure DbQueryReader::get_query_structure() const {
    return query_structure;
}
