import QtQuick
import QtQuick.Controls
import Theme.Catppuccin.Theme
import Theme.Catppuccin.Palette
import Theme.Catppuccin.Color

Window {
    id: mainWindow

    property alias theme: catppuccinTheme
    property alias themeAnimation: colorAnimation
    property int bgColor: CatppuccinColor.Base
    property real alpha: 1.0

    color: theme.alpha(theme.get_color(bgColor), alpha)

    MouseArea {
        id: dragArea
        anchors.fill: parent
        property int mouseXOffset: 0
        property int mouseYOffset: 0

        property bool dragging: false

        Connections {
            target: dragArea
            function onPressed(mouse) {
                dragArea.mouseXOffset = mouse.x
                dragArea.mouseYOffset = mouse.y
                dragArea.dragging = true
                mainWindow.startSystemMove()
            }
            function onPositionChanged(mouse) {
                if (dragArea.dragging) {
                    mainWindow.x += mouse.x - dragArea.mouseXOffset
                    mainWindow.y += mouse.y - dragArea.mouseYOffset
                }
            }
            function onReleased() {
                dragArea.dragging = false
            }
        }
    }

    CatppuccinTheme {
        id: catppuccinTheme

        onThemeChanged: {
            colorAnimation.target = mainWindow
            colorAnimation.from = mainWindow.color
            colorAnimation.to = catppuccinTheme.get_color(mainWindow.bgColor)
            colorAnimation.start()
        }
    }

    ColorAnimation {
        id: colorAnimation
        target: mainWindow
        duration: 400
        properties: "color"
        easing.type: Easing.InOutCirc
    }

    function setAlpha(distColor, alpha) {
        // 将字符串颜色转换为 Qt.rgba() 格式
        var color = Qt.rgba(parseInt(distColor.substr(1, 2), 16) / 255,
                            parseInt(distColor.substr(3, 2), 16) / 255,
                            parseInt(distColor.substr(5, 2), 16) / 255, alpha)
        return color
    }
}
