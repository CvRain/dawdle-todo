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

    ExpandableList {
        id: todoSideBar
        z: 10
        height: parent.height - windowTitle.height
        width: 400
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: windowTitle.bottom
        anchors.topMargin: 0
        // minWidth: 48
        // maxWidth: 160
    }

    StackView {
        id: pagesView
        width: parent.width - todoSideBar.width
        height: parent.height - windowTitle.height
        anchors.top: windowTitle.bottom
        anchors.topMargin: 10
        anchors.left: todoSideBar.right
        anchors.leftMargin: 5
        initialItem: taskOverview
    }

    Component {
        id: taskOverview
        TaskOverviewGroup {}
    }

    Component {
        id: taskBaseDetail
        TaskDetailBase {
            width: pagesView.width
            height: pagesView.height
        }
    }

    Popup {
        id: popup
        anchors.centerIn: parent
        width: 300
        height: 200

        background: Rectangle {
            color: latte.Mantle
            radius: 15
            border.color: latte.Peach
        }

        TaskCreationPopup {
            anchors.fill: parent
            width: parent.width
            height: parent.height
        }

        Component.onCompleted: {
            popup.visible = false
        }
    }

    Latte {
        id: latte
    }
}
