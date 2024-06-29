//
// Created by cvrain on 24-6-26.
//

#ifndef DAWDLE_TODO_PANEL_MANAGER_HPP
#define DAWDLE_TODO_PANEL_MANAGER_HPP

#include <QObject>
#include <QMap>
#include <QQmlComponent>
#include <QQuickWindow>

namespace Utils {

    class PanelManager : public QObject {
    Q_OBJECT

    public:
        explicit PanelManager(QObject *parent = nullptr);

        Q_INVOKABLE void open_panel(const QString &panelType, const QString &panelUrl);

        Q_INVOKABLE void close_all_pane();

        Q_INVOKABLE void close_panel(const QString &panelType);

    private:
        QMap<QString, QQuickWindow *> m_openPanels;
        QQmlEngine *m_engine;


    };

} // Utils

#endif //DAWDLE_TODO_PANEL_MANAGER_HPP
