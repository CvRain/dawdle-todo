//
// Created by cvrain on 2025/10/1.
//

#ifndef DAWDLETODO_SAVE_SERVICE_HPP
#define DAWDLETODO_SAVE_SERVICE_HPP

#include <QString>
#include <SQLiteCpp/SQLiteCpp.h>
#include <optional>

class SaveService
{
public:
    explicit SaveService(const QString& savePath = "./todo.db3");
private:
    static std::optional<QString> readSqlSource(const QString& sourcePath);
    SQLite::Database db;

};


#endif //DAWDLETODO_SAVE_SERVICE_HPP