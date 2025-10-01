//
// Created by cvrain on 2025/9/25.
//

#ifndef DAWDLE_TODO_APPLICATION_HPP
#define DAWDLE_TODO_APPLICATION_HPP
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "saveService.hpp"

class Application {
public:
    explicit Application(int argc, char** argv);
    [[nodiscard]] static int exec();
private:
    void init() const;

    static void listQrcFiles(const QString &dirPath);

    QGuiApplication app;
    QQmlApplicationEngine engine;
    std::shared_ptr<SaveService> saveService;
};


#endif //DAWDLE_TODO_APPLICATION_HPP