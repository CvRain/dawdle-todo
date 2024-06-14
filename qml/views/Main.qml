import QtQuick
import QtQuick.Controls
import Theme.Catppuccin.Theme
import Theme.Catppuccin.Palette

//import "../utils"
import "../components"

Window {
    id: root
    width: 400
    height: 640
    visible: true
    color: catppuccinTheme.base()
    title: qsTr("dawdle-todo")
    flags: Qt.FramelessWindowHint

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
