#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickWindow>

#include <algorithm>
#include <exception>

#include "catppuccin_latte.h"
#include "main_window.hpp"
#include "todo_title_model.hpp"

template<typename T>
concept is_widget = std::is_base_of_v<QQuickItem, T>
                    || std::is_base_of_v<QWindow, T>
                    || std::is_same_v<T, QQuickItem>;

template<is_widget T>
T *get_widget_object(QQmlApplicationEngine &engine, const QString &widget_name);

int main(int argc, char *argv[]) {
    const QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;

    qmlRegisterType<Theme::Catppuccin::Latte>("Theme.Catppuccin.Latte", 1, 0, "Latte");
    qmlRegisterType<Model::TodoTitleModel>("Model.TodoTitle",1,0,"TodoTitle");

    const QUrl url(u"qrc:/dawdle_todo/component/Main.qml"_qs);
    QObject::connect(
            &engine,
            &QQmlApplicationEngine::objectCreated,
            &app,
            [url](const QObject *obj, const QUrl &objUrl) {
                if (!obj && url == objUrl)
                    QCoreApplication::exit(-1);
            },
            Qt::QueuedConnection);
    engine.load(url);

    auto main_window = std::make_shared<Widgets::MainWindow>(
            get_widget_object<QQuickWindow>(engine, "mainWindow"), nullptr);

    return QGuiApplication::exec();
}

template<is_widget T>
T *get_widget_object(QQmlApplicationEngine &engine, const QString &widget_name) {
    try {
        auto rootObjects = engine.rootObjects();
        auto widget_iter = std::find_if(rootObjects.begin(), rootObjects.end(), [&](QObject *object) {
            return object->objectName() == widget_name;
        });

        if (widget_iter == rootObjects.end()) {
            qWarning("Failed to find main window object");
            throw std::runtime_error("Failed to find " + widget_name.toLocal8Bit());
        }

        auto widget = qobject_cast<T *>(*widget_iter);
        if (!widget) {
            throw std::runtime_error("Exception::Failed to cast widget to *" + widget_name.toLocal8Bit());
        }

        return widget;

    } catch (const std::exception &exception) {
        qDebug() << exception.what();
        return nullptr;
    }
}
