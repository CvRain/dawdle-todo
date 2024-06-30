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
}
