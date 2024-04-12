import QtQuick
import QtQuick.Controls
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
        anchors.fill: parent
        color: latteTheme.Surface0

        TitleButton {
            id: iconContainer
            height: titleBar.height * 0.6
            width: titleBar.height * 0.6
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.verticalCenter: parent.verticalCenter
            iconPath: "qrc:/img/home.svg"
        }

        Text {
            id: title
            text: titleText
            font.weight: Font.Bold
            width: parent.width / 2
            height: parent.height
            anchors.left: iconContainer.right
            anchors.leftMargin: 5
            anchors.verticalCenter: parent.verticalCenter
            color: latteTheme.Subtext1
            verticalAlignment: Text.AlignVCenter
            clip: true
            horizontalAlignment: Text.AlignLeft
        }

        TitleButton {
            id: exitWindow
            width: titleBar.height * 0.4
            height: titleBar.height * 0.4
            iconPath: "qrc:/img/exit.svg"
            anchors.right: parent.right
            anchors.rightMargin: 15
            anchors.verticalCenter: parent.verticalCenter
        }
        TitleButton {
            id: maxWindow
            width: titleBar.height * 0.4
            height: titleBar.height * 0.4
            iconPath: "qrc:/img/max.svg"
            anchors.right: exitWindow.left
            anchors.rightMargin: 10
            anchors.verticalCenter: parent.verticalCenter
        }
        TitleButton {
            id: minWindow
            width: titleBar.height * 0.4
            height: titleBar.height * 0.4
            iconPath: "qrc:/img/min.svg"
            anchors.right: maxWindow.left
            anchors.rightMargin: 10
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    Connections {
        target: iconContainer
        function onIconClicked() {
            titleIconClicked()
            console.log(randomValue.generate_string(10))
        }
    }

    RandomValue {
        id: randomValue
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
        //TODO 好难啊，写不出来
        function onIconClicked() {
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

    Latte {
        id: latteTheme
    }
}
