import QtQuick 2.0
import QtQuick.Controls
import Theme.Catppunccin.Latte
import Model.TodoTitle

Item {
    id: root

    signal itemDelete
    signal itemClicked

    Rectangle {
        id: taskGroupdBackground
        color: latte.Base
        anchors.fill: parent

        ListView {
            id: taskListView
            anchors.fill: parent
            spacing: 15
            clip: true
            model: TodoTitle {
                id: todoTitleModel
            }

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

                    swipe.left: Button {
                        width: swipeDel.width / 10
                        height: swipeDel.height
                        text: "Delete"

                        background: Rectangle {
                            color: latte.Rosewater
                            border.color: latte.Flamingo
                            radius: 15
                        }

                        function onClicked(mouse) {
                            removeAnimation.start()
                        }

                        NumberAnimation {
                            id: removeAnimation
                            target: swipeDel.contentItem
                            property: "opacity"
                            to: 0
                            duration: 200 // milliseconds
                            onStopped: {
                                todoTitleModel.remove(index)
                            }
                        }
                    }
                }
            }
        }
    }

    Latte {
        id: latte
    }
}