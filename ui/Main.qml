import QtQuick

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("dawdle-todo")

    Rectangle {
        id: mainContainer
        anchors.fill: parent
        color: "#1E1E2E"

        Image {
            anchors.fill: parent
            source: "qrc:/img/banner-main-2.jpg"
            autoTransform: true
            fillMode: Image.PreserveAspectCrop
        }

        Placeholder {
            id: placeholder
            width: parent.width - 40
            height: parent.height / 5
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 20
        }

        ListView {
            id: taskList
            delegate: taskDelegate
            width: placeholder.width - 5
            height: parent.height - placeholder.height - bottomPanel.height
            anchors.top: placeholder.bottom
            anchors.topMargin: 20
            anchors.horizontalCenter: placeholder.horizontalCenter
            spacing: 10
            model: ListModel {
                id: taskListModel
                ListElement {
                    name: "Hello"
                }
            }
        }

        Component {
            id: taskDelegate
            TaskBar {
                taskName: name
                height: 35
                width: placeholder.width - 5
            }
        }

        BottomPanel {
            id: bottomPanel
            width: parent.width
            height: 30
            anchors.bottom: mainContainer.bottom
        }

        Connections {
            target: bottomPanel
            function onAddNewTodo(taskContent) {
                console.log(taskContent)
                taskListModel.append({
                                         "name": taskContent
                                     })
            }
        }
    }
}
