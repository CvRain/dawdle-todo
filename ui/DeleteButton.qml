import QtQuick

Item {
    id: root
    required width
    required height

    Rectangle{
        color: "transparent"
        anchors.fill: parent
        width: parent.width
        height: parent.height
        Image {
            id: deleteIcon
            source: "qrc:/img/delete.svg"
            anchors.fill: parent
            width: parent.width
            height: parent.height
        }
    }
}
