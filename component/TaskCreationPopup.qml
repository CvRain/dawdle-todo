import QtQuick 2.0
import QtQuick.Controls
import Theme.Catppunccin.Latte

Item {
    id: root
    width: 300
    height: 200

    property string todoName: ""
    property string todoType: ""

    Rectangle {
        id: todoDialog
        anchors.fill: parent
        color: latte.Mantle

        signal todoCreated(string name, string type)

        Text {
            id: title
            text: qsTr("New task group")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            width: parent.width * 0.8
            height: 25
            font.pixelSize: 16
            font.bold: true
            color: latte.DefaultText

            anchors {
                top: parent.top
                topMargin: 15
                horizontalCenter: parent.horizontalCenter
            }
        }

        TextInput {
            id: nameInput
            width: parent.width * 0.8
            height: 25
            font.pixelSize: 14
            font.bold: true
            color: latte.Subtext0
            horizontalAlignment: Text.AlignHCenter
            anchors {
                top: title.bottom
                topMargin: 15
                horizontalCenter: parent.horizontalCenter
            }

            Rectangle {
                id: underline
                width: 55 // 初始下划线宽度
                height: 1
                color: latte.Overlay0
                anchors {
                    bottom: parent.bottom
                    bottomMargin: 2
                    horizontalCenter: nameInput.horizontalCenter
                }

                // 添加平滑过渡动画效果
                Behavior on width {
                    NumberAnimation {
                        duration: 200 // 过渡动画持续时间
                        easing.type: Easing.InOutQuad // 使用缓动函数控制动画速度
                    }
                }
            }

            onTextChanged: {
                // 根据输入文本宽度调整下划线宽度
                if (nameInput.contentWidth < 55) {
                    underline.width = 55
                } else {
                    underline.width = nameInput.contentWidth + 20
                }
            }
        }

        ComboBox {
            id: typeComboBox
            width: parent.width - 20
            height: 25
            anchors.top: nameInput.bottom
            anchors.topMargin: 15
            anchors.horizontalCenter: parent.horizontalCenter

            model: ["once", "cycle", "daily"]
            delegate: ItemDelegate {
                width: parent.width
                text: modelData
                highlighted: highlighted
                padding: 10
                font.bold: true
            }
            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: "#ffffff"
                border.color: "#000000"
                border.width: 1
                radius: 5
            }
            contentItem: Text {
                text: typeComboBox.currentText // 修改此处
                font.pixelSize: 16
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                elide: Text.ElideRight
            }
            onCurrentTextChanged: todoType = currentText
        }

        Button {
            id: createButton
            text: "Create Todo"
            width: parent.width - 20
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter

            background: Rectangle {
                color: latte.Rosewater
                border.color: latte.Flamingo
                radius: 15
            }

            onClicked: {
                if (nameInput.text.length > 0 && nameInput.error === "") {
                    todoCreated(nameInput.text, todoType)
                }
            }
        }

        Component.onCompleted: {
            nameInput.forceActiveFocus()
        }
    }

    Latte {
        id: latte
    }
}
