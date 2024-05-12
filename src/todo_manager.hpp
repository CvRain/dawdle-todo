//
// Created by cvrain on 24-5-8.
//

#ifndef DAWDLE_TODO_TODO_MANAGER_HPP
#define DAWDLE_TODO_TODO_MANAGER_HPP

#include <QObject>
#include <QString>
#include <string>
#include <string_view>
#include "singleton_database.hpp"
#include "todo_structure.h"

class TodoManager : public QObject{
    Q_OBJECT
public:
    explicit TodoManager(QObject *object = nullptr);
    Q_INVOKABLE void new_todo_group(const QString& group_text, const QString& category_text);
private:
    TodoStructure::TodoGroupInfo todo_head_serialization(const std::string_view& json_string);
    std::string todo_head_deserialization(const TodoStructure::TodoGroupInfo& todo_info_value);
};


#endif //DAWDLE_TODO_TODO_MANAGER_HPP
