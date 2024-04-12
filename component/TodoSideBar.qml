import QtQuick

import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 2.1
import Catppunccin

//import QtGraphicalEffects 1.0
Item {
    property bool unfold: false
    property real minWidth: 64
    property real maxWidth: 240
    id: root
    width: 480
    height: 640

    Rectangle {
        id: barRect
        width: unfold ? maxWidth : minWidth
        height: parent.height
        //radius: 10
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        color: latte.Mantle
        border.color: latte.Peach
        clip: true

        Behavior on width {
            NumberAnimation {
                duration: 300
            }
        }

        ListModel {
            id: appModel
            ListElement {
                name: "Home"
                icon: "qrc:/img/home.svg"
            }
            ListElement {
                name: "Profile"
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
                name: "Sign Out"
                icon: "qrc:/img/home.svg"
            }
        }

        Component {
            id: appDelegate
            Rectangle {
                id: delegateBackground
                width: barRect.width
                height: 48
                radius: 5
                color: "#00000000"
                //显示图标
                Image {
                    id: imageIcon
                    width: 24
                    height: 24
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 18
                    source: icon
                }
                //显示APP文字
                Text {
                    anchors.left: imageIcon.right
                    anchors.leftMargin: 20
                    anchors.verticalCenter: imageIcon.verticalCenter
                    color: latte.Subtext1
                    text: name
                    font {
                        pixelSize: 20
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

        GridView {
            id: appGrid
            width: 160
            height: parent.height
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.topMargin: 12
            model: appModel
            delegate: appDelegate
            cellWidth: width
            cellHeight: 60
            clip: true
        }
    }

    // 展开/收回按钮
    Rectangle {
        width: 34
        height: width
        radius: width / 2
        color: latte.Flamingo
        border.color: latte.Yellow
        border.width: 1
        anchors.left: barRect.right
        anchors.leftMargin: -width / 2
        anchors.bottom: barRect.bottom
        Image {
            width: 24
            height: 24
            anchors.centerIn: parent
            //此处使用旋转1180度实现展开按钮图标和收回按钮图标
            rotation: unfold ? 180 : 0
            source: "qrc:/img/add.svg"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                unfold = !unfold
            }
        }
    }

    Latte {
        id: latte
    }
}
