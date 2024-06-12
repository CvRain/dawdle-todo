#include <QGuiApplication>
#include <QUrl>
#include <QQmlApplicationEngine>
#include "model/catppuccin_palette_type.hpp"
#include "theme/catppuccin_provider.hpp"

#include <spdlog/spdlog.h>

#include "services/database_service.hpp"
#include "model/todo_group.hpp"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    Service::DatabaseService::get_instance().add_one(Model::create_todo_group("test", Model::TodoCategory::Cycle));
    Service::DatabaseService::get_instance().add_one(Model::create_todo_group("test2", Model::TodoCategory::Cycle));
    Service::DatabaseService::get_instance().print_all();

    qmlRegisterType<Theme::CatppuccinProvider>("Theme.Catppuccin.Theme", 1, 0, "CatppuccinTheme");
    spdlog::info("Register qml type: Theme::CatppuccinProvider");

    qmlRegisterType<Model::CatppuccinPaletteType>("Theme.Catppuccin.Palette", 1, 0, "CatppuccinType");
    spdlog::info("Register qml type: Model::CatppuccinPaletteType");

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
    spdlog::info("Load qml from module: dawdle_todo");

    return QGuiApplication::exec();
}
