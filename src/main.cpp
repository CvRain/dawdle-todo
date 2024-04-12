#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "catppuccin_latte.h"
#include "random_value.hpp"

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

    return QGuiApplication::exec();
}
