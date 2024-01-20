import QtQuick
import QtQuick.Controls

Item{
    id: root
    width: parent.width
    height: 50
    property string taskName : "啊啊啊啊！好想摆烂啊"
    property string taskDescription : "Enter a description for this task"
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
            width: 20
            height: 20
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

            MouseArea {
                anchors.fill: parent
                onDoubleClicked: {
                    taskNameInput.readOnly = false
                    taskNameInput.forceActiveFocus()
                }

                onExited: {
                    taskNameInput.readOnly = true
                    taskNameInput.forceActiveFocus()
                    taskNameInput.textChanged()
                }
            }

            Component.onCompleted: {
                    taskNameInput.forceActiveFocus()
            }
        }


        
    }
}
