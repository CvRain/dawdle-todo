import QtQuick

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("dawdle-todo")

    Rectangle{
        anchors.fill: parent
        color: "#1E1E2E"

        Image{
            anchors.fill: parent
            source: "qrc:/img/banner-main-2.jpg"
            autoTransform: true
            fillMode: Image.PreserveAspectCrop

            Placeholder{
                id: placeholder
                width: parent.width - 40
                height: parent.height / 5
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 20
            }

            TaskBar{
                id: taskBar
                width: placeholder.width - 5
                height: 30
                anchors.top: placeholder.bottom
                anchors.topMargin: 20
                anchors.horizontalCenter: placeholder.horizontalCenter
            }
        }
    }
}
