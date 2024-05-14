//
// Created by cvrain on 24-5-8.
//

#ifndef DAWDLE_TODO_TODO_MANAGER_HPP
#define DAWDLE_TODO_TODO_MANAGER_HPP

#include <QObject>
#include <QString>
#include <string>
#include <string_view>
#include "todo_structure.h"
#include "database_service.hpp"

namespace Controller {
    class TodoManager : public QObject {
    Q_OBJECT

    public:
        explicit TodoManager(QObject *parent = nullptr);

        Q_INVOKABLE void new_todo_group(const QString &group_text, const QString &category_text);

        Q_INVOKABLE std::vector<TodoStructure::TodoGroupInfo> get_all_todo_group();

    private:
        static std::optional<TodoStructure::TodoGroupInfo> todo_head_serialization(const std::string_view &json_string);

        static std::string todo_head_deserialization(const TodoStructure::TodoGroupInfo &todo_info_value);

        LevelDatabase& database_instance = LevelDatabase::get_instance();
    };
}


#endif //DAWDLE_TODO_TODO_MANAGER_HPP
