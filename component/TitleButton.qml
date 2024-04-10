import QtQuick
import QtQuick.Controls
import Catppunccin

Item {
    id: root
    width: 64
    height: 64

    property string iconPath: "qrc:/img/home.svg"
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

            onEntered: {
                colorAnimation.from = iconContainer.color
                colorAnimation.to = hoverColor
                colorAnimation.start()
                iconEntered()
            }

            onExited: {
                // Start the timer to reset the color after a short delay
                colorResetTimer.restart()
                iconExited()
            }

            onCanceled: {
                colorResetTimer.restart()
                iconExited()
            }

            onClicked: {
                colorAnimation.from = iconContainer.color
                colorAnimation.to = pressedColor
                colorAnimation.start()
                iconClicked()
                console.log("TitleButton::clicked")
            }
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

    Latte {
        id: latteTheme
    }
}
