#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "catppuccin_latte.h"
#include "random_value.hpp"

#include <memory>

int main(int argc, char *argv[])
{
    const QGuiApplication app(argc, argv);

    qmlRegisterType<Theme::Catppuccin::Latte>("Catppunccin",1,0,"Latte");

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("RandomValue",Tools::Debug::RandomValue::get_instance().get());

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
