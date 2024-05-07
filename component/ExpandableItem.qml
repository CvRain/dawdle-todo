import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: root
    property string text
    property var subItems
    property bool expanded: false

    Rectangle {
        anchors.fill: parent
        color: "lightgray"
        border.color: "black"
        border.width: 1

        Text {
            text: root.text
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 10
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                root.expanded = !root.expanded
            }
        }
    }

    ListView {
        id: subListView
        anchors {
            left: parent.left
            right: parent.right
            top: parent.bottom
        }
        model: subItems
        delegate: ItemDelegate {
            text: name
        }
        visible: root.expanded
    }
}
