import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Theme.Catppuccin.Theme
import Theme.Catppuccin.Palette
import Theme.Catppuccin.Color
import Utils.PanelManager

//import "../utils"
import "../components"

MoveableWindow {
    id: root
    width: 400
    height: 640
    visible: true
    bgColor: CatppuccinColor.Base
    title: qsTr("dawdle-todo")
    flags: Qt.FramelessWindowHint | Qt.Window

    PanelManager {
        id: panelManager
    }

    WindowTitle {
        id: windowTitle
        width: parent.width
        height: 40
        anchors.top: parent.top
        distWindow: root
        z: 10

        Connections {
            target: windowTitle
            function onThemeButtonClicked(isDark) {
                if (isDark) {
                    theme.switch_theme(CatppuccinType.Latte)
                } else {
                    theme.switch_theme(CatppuccinType.Mocha)
                }
            }
        }
    }

    ColumnLayout {
        width: 200
        height: 300
        anchors.centerIn: parent
        Button {
            text: "TimeDisplay"
            onClicked: panelManager.open_panel(
                           "TimeDisplay", ":/qml/views/TimeDisplayPanel.qml")
        }
        Button {
            text: "WeatherPanel"
            onClicked: panelManager.open_panel("WeatherPanel",
                                               ":/qml/views/WeatherPanel.qml")
        }
        Item {
            Layout.fillHeight: true
        } // Spacer
    }
}
