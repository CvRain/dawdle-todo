import QtQuick

Item {
    id: taskFromComponent
    width: parent.width
    height: parent.height

    signal addNewTodo(string taskContent)

    Rectangle {
        id: taskForm
        width: parent.width
        height: parent.height
        radius: 15
        color: "#991e1e2e"
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5

        TextInput {
            id: taskInput
            height: parent.height
            width: parent.width - parent.height - 20
            anchors.left: parent.left
            anchors.leftMargin: 10
            color: "white"
            font.pixelSize: 14
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter

            Connections {
                target: taskInput
                function onTextEdited() {
                    uploadIcon.visible = taskInput.length === 0 ? false : true
                }
            }
        }

        Rectangle {
            id: taskSubmit
            height: parent.height / 2.5
            width: parent.height / 2.5
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            color: "transparent"
            Image {
                id: uploadIcon
                anchors.fill: parent
                source: "qrc:/img/upload.svg"
                visible: false
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    addNewTodo(taskInput.text)
                }
            }
        }
    }
}
