#include <QGuiApplication>
#include <QUrl>
#include <QQmlApplicationEngine>
#include <QFile>

#include "model/catppuccin_palette_type.hpp"
#include "theme/catppuccin_provider.hpp"
#include "utils/panel_manager.hpp"

#include <spdlog/spdlog.h>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    //Service::TodoGroupTable::add_one(Model::create_todo_group("testaa", Model::TodoCategory::Cycle));
    //Service::TodoGroupTable::print_all();

    qmlRegisterType<Theme::CatppuccinProvider>("Theme.Catppuccin.Theme", 1, 0, "CatppuccinTheme");
    spdlog::info("Register qml type: Theme::CatppuccinProvider");

    qmlRegisterType<Model::CatppuccinPaletteType>("Theme.Catppuccin.Palette", 1, 0, "CatppuccinType");
    spdlog::info("Register qml type: Model::CatppuccinPaletteType");

    qmlRegisterType<Model::CatppuccinColor>("Theme.Catppuccin.Color", 1, 0, "CatppuccinColor");
    spdlog::info("Register qml type: Model::CatppuccinColor");

    qmlRegisterType<Utils::PanelManager>("Utils.PanelManager", 1, 0, "PanelManager");
    spdlog::info("Register qml type: Utils::PanelManager");

    QQmlApplicationEngine engine;

    const auto entryQmlPath = QUrl(u"qrc:/qml/views/Main.qml"_qs);
    //check file exist
    // if (!QFile::exists(entryQmlPath.toLocalFile())) {
    //     spdlog::error("Qml file not found: {}", entryQmlPath.toLocalFile().toStdString());
    //     return -1;
    // }
    spdlog::info("load qml: {}", entryQmlPath.toLocalFile().toStdString());
    engine.load(entryQmlPath);

    return QGuiApplication::exec();
}
