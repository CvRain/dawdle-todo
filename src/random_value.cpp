#include "random_value.hpp"
#include <random>
#include <sstream>
#include <mutex>
#include <QString>
#include <QDebug>

namespace Tools::Debug {
    Q_GLOBAL_STATIC(QSharedPointer<RandomValue>, randomValueInstance)
    QMutex RandomValue::mutex;

    int RandomValue::generate_number(int min, int max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(min, max);
        return dis(gen);
    }

    QString RandomValue::generate_string(int length) {
        std::stringstream ss;
        for (int i = 0; i < length; ++i) {
            ss << static_cast<char>(generate_number('a', 'z'));
        }
        qDebug() << ss.str().data();
        return QString::fromStdString(ss.str());
    }

    QSharedPointer<RandomValue> RandomValue::get_instance(QObject *parent) {
        QMutexLocker locker(&RandomValue::mutex);
        if (!*randomValueInstance) {
            *randomValueInstance = QSharedPointer<RandomValue>(new RandomValue(parent), &QObject::deleteLater);
        }
        return *randomValueInstance;
    }
}
