import QtQuick
import Theme.Catppuccin.Theme

import "../components"

Window {
    id: root
    width: 300
    height: 80
    visible: true
    color: catppuccinTheme.base()
    title: qsTr("dawdle-todo")
    flags: Qt.FramelessWindowHint | Qt.Window

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
