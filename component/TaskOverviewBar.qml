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
                acceptedButtons: Qt.RightButton

                onPressed: function (mouse) {
                    if (mouse.button === Qt.RightButton) {
                        popupMenu.x = mouse.x
                        popupMenu.y = mouse.y
                        popupMenu.open()
                    }
                }
            }
        }
    }

    Popup {
        id: popupMenu
        width: 100
        height: 120
        padding: 10
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent
        contentItem: Rectangle {
            width: parent.width
            height: parent.height
            color: "#f0f0f0"
            radius: 5
            border.color: latteTheme.Flamingo
            border.width: 1

            Column {
                spacing: 5
                Button {
                    text: "Open"
                    onClicked: {
                        console.log("Open clicked!")
                        popupMenu.close()
                    }
                }
                Button {
                    text: "Edit"
                    onClicked: {
                        console.log("Edit clicked!")
                        popupMenu.close()
                    }
                }
                Button {
                    text: "Delete"
                    onClicked: {
                        console.log("Delete clicked!")
                        popupMenu.close()
                    }
                }
            }
        }
    }

    Latte {
        id: latteTheme
    }
}
