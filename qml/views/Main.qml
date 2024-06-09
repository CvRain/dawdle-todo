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
    }

    // MouseArea {
    //     id: mouseRegion
    //     anchors.top: windowTitle.bottom
    //     width: parent.width
    //     height: parent.height - windowTitle.height

    //     acceptedButtons: Qt.LeftButton | Qt.RightButton
    // }
    Switch {
        id: switchButton
        anchors.top: windowTitle.bottom
        anchors.right: windowTitle.right
        anchors.topMargin: 10
        anchors.rightMargin: 10
        onClicked: {
            if (!switchButton.checked) {
                catppuccinTheme.switch_theme(CatppuccinType.Latte)
            } else {
                catppuccinTheme.switch_theme(CatppuccinType.Mocha)
            }
            windowTitle.switchTheme(!switchButton.checked)
        }
    }

    // Connections {
    //     target: mouseRegion

    //     function onClicked(mouse) {
    //         if (mouse.button === Qt.RightButton) {
    //             contentMenu.popup()
    //         }
    //     }
    // }
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
