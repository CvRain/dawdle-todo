import QtQuick
import QtQuick.Window
import QtQuick.Controls
import Theme.Catppunccin.Latte
import Model.TodoTitle

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
        maxWidth: 160
    }

    StackView {}

    TaskOverviewGroup {
        id: taskOverviewGroup
        width: parent.width - todoSideBar.width
        height: parent.height - windowTitle.height
        anchors.top: windowTitle.bottom
        anchors.topMargin: 10
        anchors.left: todoSideBar.right
        anchors.leftMargin: 5
    }

    Connections {
        target: todoSideBar
        function onExpandButtonClick(unfold) {//TODO expand animation
            // taskOverviewGroup.taskGroupdBgWidthAnimation.newWidth
            //         = todoSideBar.unfold ? todoSideBar.minWidth : todoSideBar.maxWidth
            // taskOverviewGroup.taskGroupdBgWidthAnimation.start()
        }
    }

    Latte {
        id: latte
    }
}
