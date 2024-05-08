import QtQuick
import QtQuick.Window
import QtQuick.Controls
import Theme.Catppuccin.Latte
import Model.TodoTitle

Window {
    id: root
    objectName: "mainWindow"
    width: 400
    height: 640
    visible: true
    title: qsTr("dawdle-todo")
    flags: Qt.FramelessWindowHint | Qt.Window
    color: latte.Base

    MouseArea {
        id: mouseRegion
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
    }

    Connections {
        target: mouseRegion

        function onClicked(mouse) {
            if (mouse.button === Qt.RightButton) {
                contentMenu.popup()
            }
        }
    }

    HomePageMenu {
        id: contentMenu
        width: 80
        height: 100
        sourceWindow: root
    }

    Connections {
        target: contentMenu
        function onInvokeNewTodo() {
            taskCreationPopup.open()
            contentMenu.close()
        }
    }

    WindowTitle {
        id: windowTitle
        width: parent.width
        height: 40
        anchors.top: parent.top
        distWindow: root
    }

    StackView {
        id: pagesView
        anchors.top: windowTitle.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width - 20
        height: parent.height - windowTitle.height

        initialItem: taskOverview
    }

    Component {
        id: taskOverview
        TaskOverviewGroup {
            width: parent.width
            height: parent.height - windowTitle.height
        }
    }

    Component {
        id: taskBaseDetail
        TaskDetailBase {
            width: pagesView.width
            height: pagesView.height
        }
    }

    Popup {
        id: taskCreationPopup
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
    }

    Latte {
        id: latte
    }
}
