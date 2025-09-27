//
// Created by cvrain on 2025/9/25.
//

#include "application.hpp"

#include <QDir>
#include <QResource>
#include <QFileInfoList>
#include <QStandardPaths>
#include <QUrl>
#include <QDebug>

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

    engine.loadFromModule("DawdleTodo", "Main");
}

int Application::exec() {
    return QGuiApplication::exec();
}

void Application::init() {
    QGuiApplication::setApplicationVersion("1.0.0");
    QGuiApplication::setApplicationName("com.rainer.dawdle-todo");

    const auto& importPathList = engine.importPathList();
    for (const auto& it: importPathList) {
        qDebug() <<"Import path: " << it;
    }

    //递归列出qrc:/qt/qml下的所有文件
    qDebug() << "Listing qrc:/qt/qml";
    listQrcFiles(":/qt/qml");

    init_database();
}

void Application::listQrcFiles(const QString& dirPath) {
    const QDir dir(dirPath);
    
    // 检查目录是否存在
    if (!dir.exists()) {
        qDebug() << "Directory does not exist:" << dirPath;
        return;
    }

    // 列出所有文件和目录
    QFileInfoList entries = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    for (const QFileInfo& fileInfo : entries) {
        qDebug() << fileInfo.absoluteFilePath();
        // 如果是目录，递归列出其中的文件
        if (fileInfo.isDir()) {
            listQrcFiles(fileInfo.absoluteFilePath());
        }
    }
}

void Application::init_database() {
    //todo db.exec("CREATE TABLE IF NOT EXIST ");
}
