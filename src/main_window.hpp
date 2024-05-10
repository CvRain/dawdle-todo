//
// Created by cvrain on 24-4-14.
//

#ifndef DAWDLE_TODO_MAIN_WINDOW_HPP
#define DAWDLE_TODO_MAIN_WINDOW_HPP

#include <QQuickWindow>
#include <QObject>

#include <memory>

namespace Widgets{
    class MainWindow : public QObject{
    Q_OBJECT
    public:
        explicit MainWindow(QQuickWindow *window,QObject* parent = nullptr);
        void moveWindow(int x, int y);
    private:
        std::unique_ptr<QQuickWindow> main_window;
    };
}

#endif //DAWDLE_TODO_MAIN_WINDOW_HPP
