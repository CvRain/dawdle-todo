import QtQuick 2.15
import QtQuick.Controls 2.15
import Model.TwoLevelList

Item {
    id: root
    width: 300
    height: 400

    TwoLevelList {
        id: backend
    }

    ListView {
        id: listView
        anchors.fill: parent
        model: backend.model // Assuming backend has a model property
        delegate: Item {
            id: delegate
            width: parent.width
            height: level1Label.height + (expanded ? level2ListView.height : 0)

            Rectangle {
                id: level1Rect
                width: parent.width
                height: level1Label.height
                color: "lightgray"
                border.color: "black"
                border.width: 1

                Label {
                    id: level1Label
                    anchors.left: parent.left
                    anchors.right: expandButton.left
                    anchors.verticalCenter: parent.verticalCenter
                    text: level1
                }

                Button {
                    id: expandButton
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    text: expanded ? "-" : "+"
                    onClicked: expanded = !expanded
                }
            }

            ListView {
                id: level2ListView
                anchors.top: level1Rect.bottom
                width: parent.width
                height: contentHeight
                visible: expanded
                model: level2 // Assuming level2 is a property of the backend model
                delegate: Label {
                    width: parent.width
                    text: styleData.value
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            property bool expanded: false
        }
    }
}
