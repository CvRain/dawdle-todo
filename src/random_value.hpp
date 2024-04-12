#ifndef DAWDLE_TODO_RANDOM_VALUE_HPP
#define DAWDLE_TODO_RANDOM_VALUE_HPP

#include <QObject>
#include <QSharedPointer>
#include <QMutex>
#include <QString>
#include <QDebug>

namespace Tools::Debug {
    class RandomValue : public QObject {
    Q_OBJECT

    public:
        explicit RandomValue(QObject *parent = nullptr) : QObject(parent) {}

        Q_INVOKABLE int generate_number(int min, int max);

        Q_INVOKABLE QString generate_string(int length);
    };
}


#endif //DAWDLE_TODO_RANDOM_VALUE_HPP
