pragma ComponentBehavior: Bound

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

        height: 46
        title: mainWindow.title
        width: parent.width

        onInvokeClose: {
            mainWindow.close();
        }
        onInvokeMaximize: {
            mainWindow.showMaximized();
        }
        onInvokeMinimize: {
            mainWindow.showMinimized();
        }
    }
    Rectangle {
        id: itemBar

        anchors.top: titleBar.bottom
        color: "#dce0e8"
        height: parent.height - titleBar.height
        width: 80
    }
    SplitView {
        id: mainContrainer

        anchors.left: itemBar.right
        anchors.top: titleBar.bottom
        height: parent.height - titleBar.height
        spacing: 0
        width: parent.width - itemBar.width

        handle: Rectangle {
            id: handleDelegate

            color: SplitHandle.pressed ? "#bcc0cc" : (SplitHandle.hovered ? "#ccd0da" : "#e6e9ef")
            implicitHeight: 4
            implicitWidth: 4

            Behavior on color{
                ColorAnimation{
                    duration: 100
                    easing.type: Easing.InOutCubic
                }
            }

            containmentMask: Item {
                height: mainContrainer.height
                width: 64
                x: (handleDelegate.width - width) / 2
            }
        }

        Rectangle {
            id: testRec

            SplitView.maximumWidth: parent.width / 3
            SplitView.minimumWidth: 80
            SplitView.preferredWidth: 160
            color: "#e6e9ef"
            height: parent.height
        }

        StackView{
            id: stackView
        }
        Rectangle {
            id: testRec2

            color: "#eff1f5"
        }
    }
}
