import QtQuick
import Theme.Catppunccin.Latte
import QtQuick.Controls

Item {
    id: root
    width: 400
    height: 40

    property string todoTitle: "unknown"
    property string todoDescribe: "no describe"

    Rectangle {
        id: main
        width: parent.width
        height: parent.height
        anchors.fill: parent
        color: latteTheme.Mantle
        border.color: latteTheme.Flamingo
        radius: 35

        CheckButton {
            id: checkButton
            radius: 6
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 5

            Connections {
                target: checkButton
                function onCheckedChanged(checked) {
                    if (checked) {
                        console.log("Checked!")
                    } else {
                        console.log("Unchecked!")
                    }
                }
            }
        }

        Text {
            id: taskName
            height: parent.height
            width: parent.width / 2
            text: todoTitle
            color: latteTheme.DefaultText
            font.pixelSize: 14
            font.bold: true
            anchors.fill: parent
            anchors.left: checkButton.right
            anchors.leftMargin: 25
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true

                // Show the tooltip when the mouse hovers over the text
                ToolTip.visible: containsMouse
                ToolTip.text: todoDescribe
                ToolTip.delay: 1000 // Delay in milliseconds before showing the tooltip
            }
        }
    }
    Latte {
        id: latteTheme
    }
}
