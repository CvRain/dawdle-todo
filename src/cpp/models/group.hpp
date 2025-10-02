//
// Created by cvrain on 2025/10/2.
//

#ifndef DAWDLETODO_GROUP_HPP
#define DAWDLETODO_GROUP_HPP

#include <QQmlEngine>

class Group: public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    explicit Group(QObject* parent = nullptr);

    int groupId{};
    QString name{};
    QString description{};
    bool isActive{};
    QString createdAt{};
};


#endif //DAWDLETODO_GROUP_HPP
