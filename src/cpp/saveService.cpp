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
    const auto sql_create_recurrence_details = readSqlSource(":/qt/qml/DawdleTodo/src/sql/create_recurrence_details.sql");
    const auto sql_create_todos = readSqlSource(":/qt/qml/DawdleTodo/src/sql/create_todos.sql");

    db.exec(sql_create_group.toLocal8Bit().toStdString());
    db.exec(sql_create_recurrence_details.toLocal8Bit().toStdString());
    db.exec(sql_create_todos.toLocal8Bit().toStdString());
}

//todo 需要将QString类型改成std::optional<QString>保证安全
QString SaveService::readSqlSource(const QString& sourcePath)
{
    QFile file(sourcePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return QString();
    }

    QTextStream in(&file);
    return in.readAll();
}
