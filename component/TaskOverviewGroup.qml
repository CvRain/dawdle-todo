import QtQuick
import QtQuick.Controls
import Theme.Catppuccin.Latte
import Model.TodoTitle
import Controller.TodoManager

Item {
    id: root
    width: 600
    height: 400

    signal itemDelete
    signal itemClicked

    Rectangle {
        id: taskGroupdBackground
        color: latte.Base
        anchors.fill: parent
        width: parent.width
        height: parent.height

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
                height: 45

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
                            todoTitle: model.group_name
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

                        onClicked: {
                            removeAnimation.start()
                        }

                        PropertyAnimation {
                            id: removeAnimation
                            target: swipeDel.contentItem
                            property: "opacity"
                            to: 0
                            duration: 200 // milliseconds
                            onStopped: {
                                //console.log(model.group_id)
                                controller.delete_todo_group(model.group_id)
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

    TodoController {
        id: controller
    }
}
