import QtQuick
import QtQuick.Controls

Item{
    id: root
    width: parent.width
    height: 50
    property string taskName : "啊啊啊啊！好想摆烂啊"
    property color defaultColor: "#771e1e2e"
    property color defaultFontColor: "#DDFFFFFF"
    property bool isCompleted : false

    Rectangle{
        id: taskbar
        anchors.fill: parent
        width: parent.width
        height: parent.height
        color: defaultColor
        border.color: Qt.darker(defaultColor, 100)
        radius: 25

        RadioRectangle{
            id: checkButton
            width: 16
            height: 16
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
        }


        TextInput{
            id: taskNameInput
            text: root.taskName
            readOnly: true
            anchors.left: checkButton.right
            anchors.leftMargin: 10
            anchors.right: parent.right
            anchors.rightMargin: 10
            font.pixelSize: 20
            color: defaultFontColor
            width: taskbar.width - saveDot.width - checkButton

            signal taskInvokeSave

            MouseArea {
                anchors.fill: parent
                onDoubleClicked: {
                    taskNameInput.readOnly = false
                    taskNameInput.forceActiveFocus()
                }
            }

            Keys.onEnterPressed: {
                saveDot.visible = false
                taskInvokeSave()
            }

            onEditingFinished: {
                saveDot.visible = false
                taskInvokeSave()
            }

            onTextChanged: {
                saveDot.visible = true
            }
        }

        Rectangle{
            id: saveDot
            width: checkButton.width / 2
            height: checkButton.width / 2
            radius: checkButton.width / 2
            color: "#77FFFFFF"
            anchors.right: taskbar.right
            anchors.rightMargin: checkButton.width / 2
            anchors.verticalCenter: parent.verticalCenter
            visible: true
        }

    }
}
