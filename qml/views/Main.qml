import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Theme.Catppuccin.Theme
import Theme.Catppuccin.Palette
import Utils.PanelManager

//import "../utils"
import "../components"

Window {
    id: root
    width: 400
    height: 640
    visible: true
    color: catppuccinTheme.base()
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
                    catppuccinTheme.switch_theme(CatppuccinType.Latte)
                } else {
                    catppuccinTheme.switch_theme(CatppuccinType.Mocha)
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

    CatppuccinTheme {
        id: catppuccinTheme
        onThemeChanged: {
            colorAnimation.target = root
            colorAnimation.from = root.color
            colorAnimation.to = catppuccinTheme.base()
            colorAnimation.start()
        }
    }

    ColorAnimation {
        id: colorAnimation
        target: root
        duration: 400
        properties: "color"
        easing.type: Easing.InOutCirc
    }
}
