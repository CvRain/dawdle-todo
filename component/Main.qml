import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window {
    id: root
    width: 740
    height: 440
    visible: true
    title: qsTr("dawdle-todo")
    flags: Qt.FramelessWindowHint | Qt.Window

    WindowTitle {
        id: windowTitle
        width: parent.width
        height: 40
        anchors.top: parent.top

        // MouseArea to handle dragging
        MouseArea {
            id: dragArea
            anchors.fill: parent
            onPressed: {
                // 记录点击时鼠标位置相对于窗口的位置
                dragArea.mouseXOffset = mouse.x
                dragArea.mouseYOffset = mouse.y
                dragArea.dragging = true
            }
            onPositionChanged: {
                // 如果鼠标已按下，则根据鼠标的移动来移动窗口
                if (dragArea.dragging) {
                    root.x += mouse.x - dragArea.mouseXOffset
                    root.y += mouse.y - dragArea.mouseYOffset
                }
            }
            onClicked: {
                console.log("clicked!")
            }
            onReleased: {
                // 鼠标释放后停止拖动
                dragArea.dragging = false
            }

            // 自定义属性来存储鼠标相对于窗口的偏移
            property int mouseXOffset: 0
            property int mouseYOffset: 0

            // 标记是否正在拖动
            property bool dragging: false
        }
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

            model: ListModel {}
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
}
