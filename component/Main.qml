import QtQuick
import QtQuick.Window
import QtQuick.Controls
import Catppunccin

Window {
    id: root
    objectName: "mainWindow"
    width: 740
    height: 440
    visible: true
    title: qsTr("dawdle-todo")
    flags: Qt.FramelessWindowHint | Qt.Window
    color: latte.Base

    WindowTitle {
        id: windowTitle
        width: parent.width
        height: 40
        anchors.top: parent.top
        anchors.topMargin: 0
        distWindow: root
    }

    TodoSideBar {
        id: todoSideBar
        z: 10
        height: parent.height - windowTitle.height
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: windowTitle.bottom
        anchors.topMargin: 0
        minWidth: 48
        maxWidth: 200
    }

    Rectangle {
        id: taskGroupdBackground

        width: parent.width - todoSideBar.width
        height: parent.height - windowTitle.height
        anchors.top: windowTitle.bottom
        anchors.left: todoSideBar.right
        anchors.leftMargin: 10
        color: latte.Base

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
                ListElement {
                    title: "hello"
                    describle: "test"
                }
            }
        }

        // NumberAnimation {
        //     id: taskGroupdBgWidthAnimation
        //     target: taskGroupdBackground
        //     property: "width"
        //     duration: 200
        //     easing.type: Easing.InOutQuad
        // }

        // Connections {
        //     target: todoSideBar
        //     function onExpandButtonClick() {
        //         taskGroupdBgWidthAnimation.start()
        //     }
        // }
    }

    Latte {
        id: latte
    }
}
