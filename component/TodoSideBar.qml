import QtQuick

import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 2.1
import Theme.Catppunccin.Latte

//import QtGraphicalEffects 1.0
Item {
    property bool unfold: false
    property real minWidth: 24
    property real maxWidth: 220

    signal expandButtonClick(bool isExpand)
    signal expandWidthChanged(real newWidth)

    width: unfold ? maxWidth : minWidth
    height: parent.height

    Rectangle {
        id: barRect
        width: unfold ? maxWidth : minWidth
        height: parent.height
        radius: 5
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        color: latte.Mantle
        border.color: latte.Peach
        clip: true

        ListModel {
            id: appModel
            ListElement {
                name: "Home"
                icon: "qrc:/img/home.svg"
            }
            ListElement {
                name: "New"
                icon: "qrc:/img/home.svg"
            }
            ListElement {
                name: "Message"
                icon: "qrc:/img/home.svg"
            }
            ListElement {
                name: "Help"
                icon: "qrc:/img/home.svg"
            }
            ListElement {
                name: "Setting"
                icon: "qrc:/img/home.svg"
            }
            ListElement {
                name: "Exit"
                icon: "qrc:/img/home.svg"
            }
        }

        Component {
            id: appDelegate
            Rectangle {
                id: delegateBackground
                width: barRect.width
                height: 40
                radius: 5
                color: "#00000000"
                //显示图标
                Image {
                    id: imageIcon
                    width: 24
                    height: 24
                    anchors {
                        verticalCenter: parent.verticalCenter
                        left: parent.left
                        leftMargin: 15
                    }
                    source: icon
                }
                //显示APP文字
                Text {
                    anchors.left: imageIcon.right
                    anchors.leftMargin: 10
                    anchors.verticalCenter: imageIcon.verticalCenter
                    color: latte.DefaultText
                    text: name
                    font {
                        pixelSize: 14
                    }
                }
                //鼠标处理
                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: delegateBackground.color = "#10000000"
                    onExited: delegateBackground.color = "#00000000"
                }
            }
        }

        ListView {
            id: appGrid
            width: 160
            height: parent.height
            anchors {
                left: parent.left
                top: parent.top
                topMargin: 12
            }
            model: appModel
            delegate: appDelegate
            // cellWidth: width
            // cellHeight: 60
            clip: true
        }
    }

    // 展开/收回按钮
    Rectangle {
        id: expandButton
        width: 34
        height: width
        radius: width / 2
        color: latte.Flamingo
        border.color: latte.Yellow
        border.width: 1
        anchors {
            left: barRect.right
            leftMargin: -width / 2
            bottom: barRect.bottom
        }
        Image {
            id: expandButtonIcon
            width: 24
            height: 24
            anchors.centerIn: parent
            //此处使用旋转180度实现展开按钮图标和收回按钮图标
            //rotation: unfold ? 180 : 0
            source: "qrc:/img/toggle-right.svg"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                unfold = !unfold
                expandButtonRotation.start()
                barWidthAnimation.start()
                expandButtonClick(unfold)
                expandWidthChanged(barRect.width)
            }
        }
    }

    NumberAnimation {
        id: barWidthAnimation
        target: barRect
        property: "width"
        duration: 300
        easing.type: Easing.InOutQuad
        from: unfold ? minWidth : maxWidth
        to: unfold ? maxWidth : minWidth
    }

    RotationAnimation {
        id: expandButtonRotation
        target: expandButton
        duration: 300
        from: unfold ? 0 : 180
        to: unfold ? 180 : 0
    }

    Latte {
        id: latte
    }
}
