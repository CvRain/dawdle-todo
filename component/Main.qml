import QtQuick
import QtQuick.Window
import QtQuick.Controls
import Catppunccin

Window {
    id: root
    width: 740
    height: 440
    visible: true
    title: qsTr("dawdle-todo")
    color: latteTheme.Base
    flags: Qt.FramelessWindowHint | Qt.Window

    WindowTitle {
        id: windowTitle
        width: parent.width
        height: 40
        anchors.top: parent.top
        distWindow: root
    }

    Rectangle {
        id: taskGroupdBackground
        width: parent.width - 30
        height: parent.height - 30
        anchors.top: windowTitle.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        anchors.leftMargin: 20
        anchors.rightMargin: 20
        anchors.bottomMargin: 20
        color: latteTheme.Base

        ListView {
            id: taskGroup
            width: parent.width
            height: parent.height
            anchors.fill: parent
            spacing: 15
            clip: true
            delegate: TaskOverviewBar {
                width: taskGroup.width
                height: 40
                todoTitle: title
                todoDescribe: describle
            }

            model: ListModel {
                // ListElement {
                //     title: RandomValue.generate_string(10)
                //     describle: RandomValue.generate_string(15)
                // }
                Component.onCompleted: {
                    append()
                }
            }
        }
    }

    TodoSideBar {
        width: root.width / 3
        height: root.height - windowTitle.height
        anchors.left: root.left
        anchors.leftMargin: 0
        anchors.top: windowTitle.bottom
        anchors.topMargin: 0
        minWidth: 64
        maxWidth: 200
    }

    Latte {
        id: latteTheme
    }
}
