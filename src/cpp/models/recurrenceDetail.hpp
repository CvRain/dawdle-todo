//
// Created by cvrain on 2025/10/2.
//

#ifndef DAWDLETODO_RECURRENCE_DETAIL_HPP
#define DAWDLETODO_RECURRENCE_DETAIL_HPP

#include <QQmlEngine>

class RecurrenceDetail : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    explicit RecurrenceDetail(QObject* parent = nullptr);

    int id{};
    int todo_id{};
    QString recurrencePatten{};
    int intervalValue{};
    QString endCondition{};
    QString endDate{};
    int totalOccurrences{};
    int completedOccurrences{};
};


#endif //DAWDLETODO_RECURRENCE_DETAIL_HPP
