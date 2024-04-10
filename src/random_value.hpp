#ifndef DAWDLE_TODO_RANDOM_VALUE_HPP
#define DAWDLE_TODO_RANDOM_VALUE_HPP

#include <QObject>
#include <QSharedPointer>
#include <QMutex>
#include <random>
#include <QString>
#include <QDebug>

namespace Tools::Debug {
    class RandomValue : public QObject {
    Q_OBJECT

    public:
        static QSharedPointer<RandomValue> get_instance(QObject *parent = nullptr);

        RandomValue(const RandomValue &) = delete;

        RandomValue &operator=(const RandomValue &) = delete;

        Q_INVOKABLE int generate_number(int min, int max);

        Q_INVOKABLE QString generate_string(int length);

    private:
        explicit RandomValue(QObject *parent = nullptr) : QObject(parent) {}

        static QSharedPointer<RandomValue> instance;
        static QMutex mutex;
    };
}


#endif //DAWDLE_TODO_RANDOM_VALUE_HPP
