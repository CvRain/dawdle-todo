//
// Created by cvrain on 2025/10/2.
//

#ifndef DAWDLETODO_TODO_HPP
#define DAWDLETODO_TODO_HPP

#include <QQmlEngine>

class Todo : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    explicit Todo(QObject* parent = nullptr);

    int todo_id{};
    int group_id{};
    QString title{};
    QString description{};
    QString dueDate{};
    int isCompleted{};
    QString completedAt{};
    int priority{};
    QString todoType{};
    int recurrenceId{};
};


#endif //DAWDLETODO_TODO_HPP
