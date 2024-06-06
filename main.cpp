#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    //qmlRegisterType<Theme::CatppuccinFactory>("Theme.Catppuccin", 1, 0, "Catppuccin");

    QQmlApplicationEngine engine;
    const auto result = QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("dawdle_todo", "Main");

    return QGuiApplication::exec();
}
