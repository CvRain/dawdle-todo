import QtQuick
import QtQuick.Controls

Item {
    id: root
    width: parent.width
    height: 50

    property color defaultColor: "#771e1e2e"
    property color defaultFontColor: "#DDFFFFFF"
    property bool isCompleted: false
    property string taskName: "no task?"

    signal invokeSave(bool isTaskFinish, string taskContent)
    signal invokeDelete

    Rectangle {
        id: taskbar
        anchors.fill: parent
        width: parent.width
        height: parent.height
        color: defaultColor
        border.color: Qt.darker(defaultColor, 100)
        radius: 25

        RadioRectangle {
            id: checkButton
            width: 16
            height: 16
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
        }

        Connections {
            target: checkButton
            function onChangeRadioStatus() {
                invokeSave(checkButton.isClicked, taskNameInput.text)
                console.log("button state: ", checkButton.isClicked)
            }
        }

        TextInput {
            id: taskNameInput
            text: root.taskName
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            readOnly: true
            anchors.left: checkButton.right
            anchors.leftMargin: 10
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 20
            color: root.defaultFontColor
            width: taskbar.width - saveDot.width - checkButton
            focus: false

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onDoubleClicked: {
                    taskNameInput.readOnly = false
                    taskNameInput.forceActiveFocus()
                }

                onPressed: {
                    var startTime = new Date().getTime()
                    longTimer.start()
                }
                onReleased: {
                    longTimer.stop()
                }

                Timer {
                    id: longTimer
                    interval: 1000
                    onTriggered: {
                        deleteIcon.active = true
                    }
                }
            }

            Keys.onEnterPressed: {
                taskNameInput.editingFinished()
            }

            Connections {
                target: taskNameInput
                function onTextEdited() {
                    saveDot.visible = true
                }
                function onEditingFinished() {
                    saveDot.visible = false
                    saveDot.forceActiveFocus()
                    taskNameInput.readOnly = true
                    taskNameInput.focus = false
                }
            }
        }

        Rectangle {
            id: saveDot
            width: checkButton.width / 2
            height: checkButton.width / 2
            radius: checkButton.width / 2
            color: "#77FFFFFF"
            anchors.right: taskbar.right
            anchors.rightMargin: checkButton.width / 2
            anchors.verticalCenter: parent.verticalCenter
            visible: false
        }
    }
    Loader {
        id: deleteIcon
        active: false
        anchors.right: parent.right
        sourceComponent: Rectangle {
            border.color: "red"
            border.width: 2
            color: transientParent
            radius: 15
            height: root.height
            width: root.height
        }
    }
}
