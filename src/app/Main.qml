import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import DawdleTodo 1.0

ApplicationWindow {
    id: mainWindow
    height: 480
    title: "Hello DawdleTodo"
    visible: true
    width: 640

    TitleBar {
        id: titleBar
        title: mainWindow.title
        height: 46
        width: parent.width
    }

    ColumnLayout{
        id: mainContainer
    }
}