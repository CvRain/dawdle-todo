//
// Created by cvrain on 24-5-13.
//

#ifndef DAWDLE_TODO_TEST_OBJECT_HPP
#define DAWDLE_TODO_TEST_OBJECT_HPP

#include <QObject>

namespace test{
    class TestObject : public QObject{
    Q_OBJECT
    public:
        explicit TestObject(QObject *parent = nullptr);
        Q_INVOKABLE void test_function();
    };
}


#endif //DAWDLE_TODO_TEST_OBJECT_HPP
