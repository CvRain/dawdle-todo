//
// Created by cvrain on 2025/10/1.
//

#include "saveService.hpp"

#include <QFile>
#include <QTextStream>

SaveService::SaveService(const QString& savePath)
    : db(savePath.toLocal8Bit().toStdString(), SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE)
{
    const auto sql_create_group = readSqlSource(":/qt/qml/DawdleTodo/src/sql/create_groups.sql");
    const auto sql_create_recurrence_details = readSqlSource(
        ":/qt/qml/DawdleTodo/src/sql/create_recurrence_details.sql");
    const auto sql_create_todos = readSqlSource(":/qt/qml/DawdleTodo/src/sql/create_todos.sql");

    if (not sql_create_group.has_value()
        || not sql_create_recurrence_details.has_value()
        || not sql_create_todos.has_value())
    {
        throw std::runtime_error("Failed to read SQL source.");
    }

    db.exec(sql_create_group.value().toLocal8Bit().toStdString());
    db.exec(sql_create_recurrence_details.value().toLocal8Bit().toStdString());
    db.exec(sql_create_todos.value().toLocal8Bit().toStdString());
}

std::optional<QString> SaveService::readSqlSource(const QString& sourcePath)
{
    QFile file(sourcePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return std::nullopt;
    }

    QTextStream in(&file);
    return in.readAll();
}
