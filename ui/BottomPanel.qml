import QtQuick

Item {
    id: root
    width: 50
    height: 50

    Rectangle{
        id: panel
        width: root.width
        height: root.height * 0.3
        color: "#881E1E2E"

        anchors.bottom: root.bottom
    }

    Rectangle{
        id: addTodo
        width: parent.height
        height: parent.height
        radius: parent.height
        anchors.horizontalCenter: parent.horizontalCenter
        color: "#1E1E2E"

        Rectangle{
            id: crossLine
            anchors.fill: parent
            color: "#00FFFFFF"

            Rectangle{
                id: transverseLine
                width: 2
                height: addTodo.height * 0.7
                color: "white"
                anchors.centerIn: parent
            }
            Rectangle{
                id: verticalLine
                width: addTodo.width * 0.7
                height: 2
                color:"white"
                anchors.centerIn: parent
            }


        }
    }
}
