import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: 400
    height: 400

    ListView {
        id: listView
        width: parent.width
        height: parent.height

        model: myModel

        delegate: Rectangle {
            width: listView.width
            height: 50

            color: index % 2 === 0 ? "lightgray" : "white"

            Text {
                anchors.centerIn: parent
                text: model.name
            }

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    // Perform an action when the item is clicked
                    console.log("Clicked:", model.name)
                }
            }
        }

        section.property: "category"
        section.criteria: ViewSection.FullString

        section.delegate: Rectangle {
            width: listView.width
            height: 30
            color: "gray"

            Text {
                anchors.centerIn: parent
                text: section

                font.bold: true
                font.pointSize: 14
            }
        }
    }

    ListModel {
        id: myModel

        ListElement {
            name: "Item 1"
            category: "Category 1"
        }
        ListElement {
            name: "Item 2"
            category: "Category 1"
        }
        ListElement {
            name: "Item 3"
            category: "Category 2"
        }
        ListElement {
            name: "Item 4"
            category: "Category 2"
        }
        ListElement {
            name: "Item 5"
            category: "Category 2"
        }
        ListElement {
            name: "Item 6"
            category: "Category 2"
        }
    }
}
