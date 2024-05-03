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
        radius: 25

        CheckButton {
            id: checkButton
            radius: 6
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 5
        }

        Text {
            id: taskName
            height: parent.height
            width: parent.width / 2
            text: todoTitle
            color: latteTheme.DefaultText
            font.pixelSize: 14
            font.bold: true
            anchors {
                fill: parent
                left: checkButton.right
                leftMargin: 25
            }

            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                acceptedButtons: Qt.RightButton
            }
        }
    }

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

    Latte {
        id: latteTheme
    }
}
