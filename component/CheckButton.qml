import QtQuick 2.0
import Theme.Catppuccin.Latte

Item {
    property real radius: 20
    width: radius * 2
    height: radius * 2

    property bool isChecked: false // 添加一个属性来跟踪勾选状态

    signal checkedChanged(bool checked)

    // 定义一个信号来通知状态变化
    Rectangle {
        id: outsideDot
        width: parent.width
        height: parent.height
        radius: parent.width / 2
        color: latteTheme.Mantle
        border.color: latteTheme.Overlay2
        anchors.fill: parent

        Rectangle {
            id: insideDot
            width: parent.width * 0.55
            height: parent.height * 0.55
            radius: insideDot.width / 2
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            color: latteTheme.Overlay2
            visible: isChecked // 根据isChecked属性来控制insideDot的可见性
        }
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: {
            isChecked = !isChecked // 切换isChecked状态
            insideDot.visible = isChecked // 根据isChecked状态更新insideDot的可见性
            checkedChanged(isChecked) // 发送信号通知状态变化
        }
    }

    Latte {
        id: latteTheme
    }
}
