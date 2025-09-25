//
// Created by cvrain on 2025/9/25.
//

#include "application.hpp"

Application::Application(int argc, char **argv)
    : app(argc, argv),
      db("todo.db3", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE) {
    init();

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("dawdle-todo", "Main");
}

int Application::exec() {
    return QGuiApplication::exec();
}

void Application::init() {
    QGuiApplication::setApplicationVersion("1.0.0");
    QGuiApplication::setApplicationName("com.rainer.dawdle-todo");

    init_database();
}

void Application::init_database() {
    //todo db.exec("CREATE TABLE IF NOT EXIST ");
}
