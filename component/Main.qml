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

    Rectangle {
        id: taskGroupdBackground

        width: root.width - todoSideBar.width - 15
        height: parent.height - windowTitle.height
        anchors.top: windowTitle.bottom
        anchors.topMargin: 10
        anchors.right: windowTitle.right
        anchors.rightMargin: 15
        color: latte.Base

        ListView {
            id: taskListView
            width: parent.width
            height: parent.height
            anchors.fill: parent
            spacing: 15
            clip: true
            model: TodoTitle {}

            delegate: Item {
                width: taskListView.width
                height: 50

                SwipeDelegate {
                    id: swipeDel
                    width: parent.width - 10
                    height: parent.height

                    background: Rectangle {
                        color: latte.Base
                        width: parent.width
                        height: parent.height
                    }
                    contentItem: Item {
                        TaskOverviewBar {
                            width: swipeDel.width
                            height: swipeDel.height
                            todoTitle: model.theme
                            todoDescribe: model.describe
                            anchors.centerIn: parent
                        }
                    }
                    swipe.left: Rectangle {
                        width: swipeDel.width / 10
                        height: swipeDel.height
                        color: latte.Rosewater
                        border.color: latte.Flamingo
                        radius: 15

                        Text {
                            width: parent.width
                            height: parent.height
                            anchors.fill: parent
                            text: "Delete"
                            font.pixelSize: 12
                            font.bold: true
                            color: latte.Mantle
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                        }
                        MouseArea {
                            anchors.fill: parent
                        }
                    }
                }
            }
        }
    }

    NumberAnimation {
        id: taskGroupdBgWidthAnimation

        property real newWidth

        target: taskGroupdBackground
        property: "width"
        duration: 500
        easing.type: Easing.InOutQuad
        from: taskGroupdBackground.width

        onRunningChanged: {
            if (running) {
                // 获取动画开始时的目标宽度
                to = root.width - newWidth - 15
            }
        }
    }

    Connections {
        target: todoSideBar
        function onExpandButtonClick(unfold) {
            taskGroupdBgWidthAnimation.newWidth
                    = unfold ? todoSideBar.minWidth : todoSideBar.maxWidth
            taskGroupdBgWidthAnimation.start()
        }
    }

    Latte {
        id: latte
    }
}
