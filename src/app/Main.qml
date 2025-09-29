import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import DawdleTodo 1.0
import QtQuick3D

ApplicationWindow {
    id: mainWindow

    height: 480
    title: "Hello DawdleTodo"
    visible: true
    width: 640

    TitleBar {
        id: titleBar

        height: 46
        title: mainWindow.title
        width: parent.width
    }

    View3D{

    }
}
