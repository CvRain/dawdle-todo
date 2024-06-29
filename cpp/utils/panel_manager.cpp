//
// Created by cvrain on 24-6-26.
//

#include "panel_manager.hpp"

#include <QFile>
#include <spdlog/spdlog.h>

namespace Utils {
    PanelManager::PanelManager(QObject *parent)
            : QObject(parent), m_engine(nullptr) {

    }

    void PanelManager::open_panel(const QString &panelType, const QString &panelUrl) {
        // 如果该类型的面板已经打开，就将其置于前台
        if (m_openPanels.contains(panelType)) {
            QQuickWindow *existingPanel = m_openPanels[panelType];
            existingPanel->raise();
            existingPanel->requestActivate();
            return;
        }

        // 创建新面板
        if (!m_engine) {
            m_engine = qmlEngine(this);
        }

        // 检查panel url处文件是否存在
        if (!QFile::exists(panelUrl)) {
            spdlog::error("Panel file not found: \"{}\"", panelUrl.toStdString());
            return;
        }
        spdlog::info("Opening panel: {}", panelUrl.toStdString());

        QQmlComponent component(m_engine, panelUrl);
        if (component.isReady()) {
            auto *obj = component.create();
            auto *panel = qobject_cast<QQuickWindow *>(obj);
            if (panel) {
                const auto result = QObject::connect(panel, &QQuickWindow::closing, this, [this, panelType]() {
                    close_panel(panelType);
                });
                m_openPanels[panelType] = panel;
                panel->show();
            } else {
                qWarning() << "Failed to create panel window";
                delete obj;
            }
        } else {
            qWarning() << "Error loading panel:" << component.errorString();
        }
    }

    void PanelManager::close_all_pane() {
        for (auto it = m_openPanels.begin(); it != m_openPanels.end(); ++it) {
            it.value()->close();
            it.value()->deleteLater();
        }
        m_openPanels.clear();
    }

    void PanelManager::close_panel(const QString &panelType) {
        if (m_openPanels.contains(panelType)) {
            m_openPanels[panelType]->deleteLater();
            m_openPanels.remove(panelType);
        }
    }
} // Utils