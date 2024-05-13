import QtQuick 2.0
import QtQuick.Controls
import Theme.Catppuccin.Latte
import Controller.TodoManager

Item {
    id: root
    width: 300
    height: 200

    property string todoName: ""
    property string todoType: ""

    FontLoader {
        id: nerdFont
        source: "qrc:/font/CascadiaCode/CaskaydiaCoveNerdFontMono-Regular.ttf"
    }

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
            font {
                pixelSize: 16
                bold: true
                family: nerdFont.name
            }

            color: latte.DefaultText
            focus: true

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
                nameAvailabilityTimer.restart()
            }
        }

        Text {
            id: nameAvailabilityText
            width: parent.width * 0.8
            height: 20
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            anchors {
                top: nameInput.bottom
                topMargin: 5
                horizontalCenter: parent.horizontalCenter
            }

            SequentialAnimation {
                id: animation
                NumberAnimation {
                    target: nameAvailabilityText
                    property: "opacity"
                    from: 0
                    to: 1
                    duration: 200
                    easing.type: Easing.InOutQuad
                }
                NumberAnimation {
                    target: nameAvailabilityText
                    property: "scale"
                    from: 0.8
                    to: 1
                    duration: 200
                    easing.type: Easing.InOutQuad
                }
            }

            onTextChanged: {
                animation.start()
            }

            Timer {
                id: nameAvailabilityTimer
                interval: 500
                onTriggered: {
                    if (nameInput.text === "") {
                        nameAvailabilityText.text = "Please enter a name"
                        nameAvailabilityText.color = latte.Peach
                    } else if (nameInput.text === "text1"
                               || nameInput.text === "text2") {
                        nameAvailabilityText.text = "Group name is exists"
                        nameAvailabilityText.color = latte.Rosewater
                    } else {
                        nameAvailabilityText.text = "Name is available"
                        nameAvailabilityText.color = latte.Teal
                    }
                }
            }

            Component.onCompleted: {
                nameAvailabilityTimer.start()
            }
        }

        ComboBox {
            id: typeComboBox
            width: parent.width - 20
            height: 25
            anchors.top: nameAvailabilityText.bottom
            anchors.topMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter

            model: ["once", "cycle", "daily"]
            delegate: ItemDelegate {
                width: parent.width
                text: modelData
                highlighted: highlighted
                padding: 10
                font.bold: true
                background: Rectangle {
                    anchors.fill: parent
                    color: latte.Mantle
                    border.color: latte.Base
                }
                font {
                    pixelSize: 12
                    bold: true
                    family: nerdFont.name
                }
                contentItem: Text {
                    text: parent.text
                    font: parent.font
                    color: latte.DefaultText // 设置按钮文字颜色
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }
            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: latte.Crust
                border.color: latte.Peach
                border.width: 1
                radius: 5
            }
            contentItem: Text {
                text: typeComboBox.currentText
                font.pixelSize: 14
                color: latte.Subtext1
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
            font {
                pixelSize: 14
                bold: true
                family: nerdFont.name
            }

            onClicked: {
                if (nameInput.text !== "") {
                    todoDialog.todoCreated(nameInput.text,
                                           typeComboBox.currentText)
                    console.log("Task Name: " + nameInput.text + ", Task Type: "
                                + typeComboBox.currentText)
                    todoManager.new_todo_group(nameInput.text,
                                               typeComboBox.currentText)
                } else {
                    console.log("Task name cannot be empty.")
                }
            }
            contentItem: Text {
                text: parent.text
                font: parent.font
                color: latte.Base
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        Component.onCompleted: {
            nameInput.forceActiveFocus()
        }
    }

    Latte {
        id: latte
    }

    TodoController {
        id: todoManager
    }
}
