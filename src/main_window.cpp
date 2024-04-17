//
// Created by cvrain on 24-4-14.
//

#include "main_window.hpp"

#include <QDebug>

namespace Widgets{

    MainWindow::MainWindow(QQuickWindow* window, QObject* parent)
    : QObject(parent), main_window(window) {
        qDebug() << "Load window: " << window->objectName();
        //window->setFlags(Qt::Window);
    }
}
