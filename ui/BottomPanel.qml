import QtQuick

Item {
    id: root
    width: 50
    height: 50

    signal addNewTodo()

    Rectangle{
        id: taskForm
        width: parent.width - addTodo.width - 20
        height: parent.height
        radius: 15
        color: "#991e1e2e"
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5

        TextInput{
            id: taskInput
            height: parent.height
            width: parent.width - parent.height - 20
            anchors.left: parent.left
            color: "white"
            font.pixelSize: 14
            horizontalAlignment: Text.AlignHCenter
        }

        Rectangle{
            id: taskSubmit
            height: parent.height / 2
            width: parent.height / 2
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            radius: height /2
            color: "#99FFFFFF"

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    //向task表中添加一条记录
                    addNewTodo()
                }
            }

        }

    }

    Rectangle{
        id: addTodo
        width: parent.height
        height: parent.height
        radius: parent.height
        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        color: "#1E1E2E"

        Rectangle{
            id: crossLine
            anchors.fill: parent
            color: "#00FFFFFF"

            Rectangle{
                id: transverseLine
                width: 2
                height: addTodo.height * 0.7
                color: "#99cfc8f4"
                anchors.centerIn: parent
            }
            Rectangle{
                id: verticalLine
                width: addTodo.width * 0.7
                height: 2
                color:"#99cfc8f4"
                anchors.centerIn: parent
            }


        }
    }
}
