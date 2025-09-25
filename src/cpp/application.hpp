//
// Created by cvrain on 2025/9/25.
//

#ifndef DAWDLE_TODO_APPLICATION_HPP
#define DAWDLE_TODO_APPLICATION_HPP
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <SQLiteCpp/SQLiteCpp.h>

class Application {
public:
    explicit Application(int argc, char** argv);
    [[nodiscard]] static int exec();
private:
    void init();
    void init_database();
    QGuiApplication app;
    QQmlApplicationEngine engine;
    SQLite::Database db;
};


#endif //DAWDLE_TODO_APPLICATION_HPP