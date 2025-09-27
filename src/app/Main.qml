import QtQuick
import QtQuick.Layouts
import DawdleTodo.src.app.Components 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello DawdleTodo")

    TitleBar{
        id: titleBar
        width: parent.width
        height: 48
    }



}