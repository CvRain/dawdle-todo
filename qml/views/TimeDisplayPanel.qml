import QtQuick
import QtQuick.Controls
import Theme.Catppuccin.Theme
import Theme.Catppuccin.Palette
import Theme.Catppuccin.Color

import "../components"

MoveableWindow {
    id: root
    width: 300
    height: 80
    visible: true
    bgColor: CatppuccinColor.Peach
    title: qsTr("dawdle-todo")
    flags: Qt.FramelessWindowHint | Qt.Window

    Button {
        property bool isLightTheme: true
        width: 20
        height: 20
        background: Rectangle {
            color: theme.subtext0()
        }
        anchors.centerIn: parent

        onClicked: {
            if (isLightTheme) {
                theme.switch_theme(CatppuccinType.Mocha)
            } else {
                theme.switch_theme(CatppuccinType.Latte)
            }
            isLightTheme = !isLightTheme
        }
    }
}
