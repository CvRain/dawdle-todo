import QtQuick
import QtQuick.Controls
import Theme.Catppuccin.Latte

Item {
    id: root
    width: 64
    height: 64

    property string iconPath: "qrc:/img/icon/home.svg"
    property color hoverColor: "gray"
    property color pressedColor: latteTheme.Subtext0

    signal iconClicked
    signal iconHovered
    signal iconEntered
    signal iconExited
    signal iconPressed

    Rectangle {
        id: iconContainer
        height: parent.height
        width: parent.height
        anchors.fill: parent
        color: "transparent"
        radius: 5

        Image {
            id: icon
            source: iconPath
            width: parent.width
            height: parent.height
            anchors.fill: parent
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true
        }

        ColorAnimation {
            id: colorAnimation
            target: iconContainer
            property: "color"
            duration: 150
        }

        // Timer to reset the color after a short delay when mouse exits
        Timer {
            id: colorResetTimer
            interval: 150 // Adjust the delay as needed
            onTriggered: {
                colorAnimation.from = iconContainer.color
                colorAnimation.to = "transparent"
                colorAnimation.start()
            }
        }
    }

    Connections {
        target: mouseArea

        function onEntered() {
            colorAnimation.from = iconContainer.color
            colorAnimation.to = hoverColor
            colorAnimation.start()
            iconEntered()
        }

        function onExited() {
            // Start the timer to reset the color after a short delay
            colorResetTimer.restart()
            iconExited()
        }

        function onCanceled() {
            colorResetTimer.restart()
            iconExited()
        }

        function onClicked() {
            colorAnimation.from = iconContainer.color
            colorAnimation.to = pressedColor
            colorAnimation.start()
            iconClicked()
            console.log("TitleButton::clicked")
        }
    }

    Latte {
        id: latteTheme
    }
}
