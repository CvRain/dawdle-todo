#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickWindow>

#include <algorithm>
#include <exception>

#include "catppuccin_latte.h"
#include "random_value.hpp"
#include "main_window.hpp"

int main(int argc, char *argv[])
{
    const QGuiApplication app(argc, argv);



    QQmlApplicationEngine engine;

    qmlRegisterType<Theme::Catppuccin::Latte>("Catppunccin",1,0,"Latte");
    qmlRegisterType<Tools::Debug::RandomValue>("Tools.Debug",1,0,"RandomValue");

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

    std::shared_ptr<Widgets::MainWindow> main_window;

    try {
        // 获取QML引擎中的根对象
        auto rootObjects = engine.rootObjects();

        // 在根对象中查找名为"mainWindow"的对象
        auto main_window_iter = std::find_if(rootObjects.begin(), rootObjects.end(), [](QObject *object) {
            return object->objectName() == "mainWindow";
        });

        // 检查是否找到了窗口对象
        if (main_window_iter == rootObjects.end()) {
            qWarning("Failed to find main window object");
            throw std::runtime_error("Failed to find main window object");
        }

        // 将QObject转换为QQuickWindow
        auto quick_window = qobject_cast<QQuickWindow*>(*main_window_iter);

        // 检查转换是否成功
        if (!quick_window) {
            qWarning("Failed to cast main window object to QQuickWindow");
            throw std::runtime_error("Failed to cast main window object to QQuickWindow");
        }

        // 使用mainWindow进行接下来的操作，比如移动窗口
        // 这里你可以调用你的移动窗口函数，传入mainWindow的位置参数
        main_window = std::make_shared<Widgets::MainWindow>(quick_window, nullptr);

    } catch (const std::exception& exception) {
        qDebug() << exception.what();
    }


    return QGuiApplication::exec();
}
