import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Catppunccin
import Tools.Debug

Item {
    property string titleText: "dawdle todo"
    property Window distWindow

    signal titleIconClicked
    signal closeButtonClicked
    signal minButtonClicked
    signal maxButtonClicked

    id: root
    width: 450
    height: 40

    Rectangle {
        id: titleBar
        width: parent.width
        height: parent.height
        color: latteTheme.Surface0

        Row {
            id: leftPart
            width: parent.width / 2
            height: parent.height
            spacing: 5

            TitleButton {
                id: iconContainer
                height: titleBar.height * 0.6
                width: titleBar.height * 0.6
                iconPath: "qrc:/img/home.svg"
                anchors.verticalCenter: parent.verticalCenter
                onIconClicked: titleIconClicked()
            }

            Text {
                id: title
                text: titleText
                font.weight: Font.Bold
                width: parent.width / 2
                height: parent.height
                color: latteTheme.Subtext1
                verticalAlignment: Text.AlignVCenter
                clip: true
                horizontalAlignment: Text.AlignLeft
                MouseArea {
                    id: dragArea
                    anchors.fill: parent
                    property int mouseXOffset: 0
                    property int mouseYOffset: 0
                    property bool dragging: false
                }
            }
        }

        RowLayout {
            id: rightPart
            width: titleBar.height * 0.4 * 3
            height: parent.height
            spacing: 5
            anchors.right: titleBar.right
            anchors.rightMargin: 10
            layoutDirection: Qt.RightToLeft
            Layout.alignment: Qt.RightToLeft

            TitleButton {
                id: exitWindow
                width: titleBar.height * 0.4
                height: titleBar.height * 0.4
                iconPath: "qrc:/img/exit.svg"
                //anchors.verticalCenter: parent.verticalCenter
                onIconClicked: closeButtonClicked()
            }

            TitleButton {
                id: maxWindow
                width: titleBar.height * 0.4
                height: titleBar.height * 0.4
                iconPath: "qrc:/img/max.svg"
                //anchors.verticalCenter: parent.verticalCenter
                onIconClicked: maxButtonClicked()
            }

            TitleButton {
                id: minWindow
                width: titleBar.height * 0.4
                height: titleBar.height * 0.4
                iconPath: "qrc:/img/min.svg"
                //anchors.verticalCenter: parent.verticalCenter
                onIconClicked: minButtonClicked()
            }
        }
    }

    Latte {
        id: latteTheme
    }

    RandomValue {
        id: randomValue
    }

    Connections {
        target: iconContainer
        function titleIconClicked() {
            console.log(randomValue.generate_string(10))
            titleIconClicked()
        }
    }

    Connections {
        target: exitWindow
        function onIconClicked() {
            console.log("WindowTitle::CloseButton::clicked")
            closeButtonClicked()
            distWindow.close()
        }
    }

    Connections {
        target: maxWindow
        function onIconClicked() {
            console.log("WindowTitle::MaxButton::clicked")
            maxButtonClicked()
            if (distWindow.Maximized) {
                distWindow.Maximized = false
                distWindow.showNormal()
                distWindow.setGeometry(0, 0, 600, 400)
            } else {
                distWindow.showMaximized()
            }
        }
    }

    Connections {
        target: minWindow
        function onIconClicked() {
            console.log("WindowTitle::MinButton::clicked")
            minButtonClicked()
            distWindow.showMinimized()
        }
    }

    Connections {
        target: dragArea

        function onPressed(mouse) {
            // 记录点击时鼠标位置相对于窗口的位置
            dragArea.mouseXOffset = mouse.x
            dragArea.mouseYOffset = mouse.y
            dragArea.dragging = true
            // console.log(mouse.x)
            // console.log(mouse.y)
        }
        function onPositionChanged(mouse) {
            // 如果鼠标已按下，则根据鼠标的移动来移动窗口
            if (dragArea.dragging) {
                distWindow.x += mouse.x - dragArea.mouseXOffset
                distWindow.y += mouse.y - dragArea.mouseYOffset
                // console.log(mouse.x)
                // console.log(mouse.y)
            }
        }
        function onReleased() {
            // 鼠标释放后停止拖动
            dragArea.dragging = false
        }
    }
}
