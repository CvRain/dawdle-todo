#include <QGuiApplication>
#include <QUrl>
#include <QQmlApplicationEngine>
#include "model/catppuccin_palette_type.hpp"
#include "theme/catppuccin_provider.hpp"


int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    qmlRegisterType<Theme::CatppuccinProvider>("Theme.Catppuccin.Theme", 1, 0, "CatppuccinTheme");
    qmlRegisterType<Model::CatppuccinPaletteType>("Theme.Catppuccin.Palette", 1, 0, "CatppuccinType");

    QQmlApplicationEngine engine;

    const auto url = QUrl(u"qrc:/dawdle_todo/qml/views/Main.qml"_qs);
    const auto result = QObject::connect(
            &engine,
            &QQmlApplicationEngine::objectCreated,
            &app,
            [url](const QObject *obj, const QUrl &objUrl) {
                if (!obj && url == objUrl) {
                    QCoreApplication::exit(-1);
                }
            },
            Qt::QueuedConnection
    );
    engine.loadFromModule("dawdle_todo", "Main");

    return QGuiApplication::exec();
}
