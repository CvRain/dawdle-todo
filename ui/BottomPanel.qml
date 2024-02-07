import QtQuick

Item {
    id: root
    width: 50
    height: 50

    signal addNewTodo(string taskContent)

    Component {
        id: panelTaskFormComponent
        PanelTaskForm {
            id: panelTaskComponent

            Connections{
                target: panelTaskComponent
                function onAddNewTodo(content){
                    root.addNewTodo(content)
                }
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

        PropertyAnimation{
            id: buttonRotation
            target: addTodo
            property: "rotation"
            from: 0
            to: 360
            duration: 1000
        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                buttonRotation.start()
            }
            onExited: {
                buttonRotation.stop()
            }

            onClicked: {
                taskFromLoader.isLoad = !taskFromLoader.isLoad
            }
        }
    }

}
