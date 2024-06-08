import QtQuick
import QtQuick.Controls
import Theme.Catppuccin.Theme
import Theme.Catppuccin.Palette

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: background
        anchors.fill: parent
        width: parent.width
        height: parent.height
        color: theme.base()
    }

    ColorAnimation {
        id: bgColorAnimation
        target: background
        duration: 400
        property: "color"
        easing.type: Easing.InOutCirc
    }

    Switch {
        id: themeSwitch
        anchors.top: parent.top
        anchors.topMargin: 15
        anchors.right: parent.right
        anchors.rightMargin: 15
        checked: true
        background: Rectangle {
            id: test
            color: theme.base()
        }

        onClicked: {
            if (themeSwitch.checked) {
                theme.switch_theme(CatppuccinType.Latte)
            } else {
                theme.switch_theme(CatppuccinType.Mocha)
            }
        }
    }

    CatppuccinTheme {
        id: theme
        Component.onCompleted: {
            theme.switch_theme(CatppuccinType.Latte)
        }

        onThemeChanged: {
            bgColorAnimation.from = background.color
            bgColorAnimation.to = theme.base()
            bgColorAnimation.start()
        }
    }
}
