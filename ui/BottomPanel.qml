import QtQuick

Item {
    id: root
    width: 50
    height: 50

    signal addNewTodo(string taskConent)

    Component {
        id: panelTaskFormComponent
        PanelTaskForm {
            onAddNewTodo: {
                root.addNewTodo(taskConent)
            }
        }
    }

    Loader {
        property bool isLoad: false

        id: taskFromLoader
        width: parent.width - addTodo.width - 20
        height: parent.height
        sourceComponent: isLoad ? panelTaskFormComponent : undefined
    }

    Rectangle {
        id: addTodo
        width: parent.height
        height: parent.height
        radius: parent.height
        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        color: "#1E1E2E"

        Image {
            id: buttonIcon
            source: "qrc:/img/add.svg"
            anchors.fill: parent
            opacity: 0.7
        }

        MouseArea {
            anchors.fill: parent
            onEntered: {
                rotationAnimation.start()
            }
            onExited: {
                rotationAnimation.stop()
            }

            onClicked: {
                taskFromLoader.isLoad = !taskFromLoader.isLoad
            }
        }
    }

    PropertyAnimation {
        id: rotationAnimation
        target: addTodo
        properties: "rotation"
        from: 0
        to: 45
        duration: 1000
        running: false
    }
}
