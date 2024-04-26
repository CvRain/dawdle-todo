import QtQuick 2.0
import QtQuick.Controls
import Theme.Catppunccin.Latte
import Model.TodoTitle

Item {
    id: root
    Rectangle {
        id: taskGroupdBackground
        color: latte.Base
        anchors.fill: parent

        ListView {
            id: taskListView
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

    Latte {
        id: latte
    }
}
