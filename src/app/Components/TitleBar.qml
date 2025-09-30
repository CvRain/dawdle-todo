import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import DawdleTodo 1.0

Item {
    id: root

    required property string title

    signal invokeClose
    signal invokeMaximize
    signal invokeMinimize

    implicitHeight: 180
    implicitWidth: 640

    Rectangle {
        id: background

        anchors.fill: parent
        color: "#ccd0da"

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
        }
    }
    RowLayout {
        id: mainContainer

        Layout.fillHeight: true
        Layout.fillWidth: true
        anchors.fill: parent
        anchors.leftMargin: 10
        anchors.rightMargin: 10

        Text {
            id: title

            color: "#4c4f69"
            font.family: CustomFont.fontComicShannsMonoRegular.name
            font.pointSize: 16
            horizontalAlignment: Text.AlignLeft
            text: root.title
            verticalAlignment: Text.AlignVCenter
        }
        Item {
            id: spacer

            Layout.fillHeight: true
            Layout.fillWidth: true
        }
        TitleButton {
            id: minimizeButton

            Layout.fillHeight: true
            Layout.maximumHeight: 25
            Layout.maximumWidth: 25
            Layout.minimumHeight: 25
            Layout.minimumWidth: 25
            Layout.preferredHeight: 25
            Layout.preferredWidth: 25

            IconMinimize {
                anchors.fill: parent
                width: parent.width
                height: parent.height
            }

            onClicked: {
                root.invokeMinimize()
            }
        }
        TitleButton {
            id: maximizeButton

            Layout.fillHeight: true
            Layout.maximumHeight: 25
            Layout.maximumWidth: 25
            Layout.minimumHeight: 25
            Layout.minimumWidth: 25
            Layout.preferredHeight: 25
            Layout.preferredWidth: 25

            IconMaximize {
                anchors.fill: parent
                width: parent.width
                height: parent.height
            }

            onClicked: {
                root.invokeMaximize()
            }
        }
        TitleButton {
            id: closeButton

            Layout.fillHeight: true
            Layout.maximumHeight: 25
            Layout.maximumWidth: 25
            Layout.minimumHeight: 25
            Layout.minimumWidth: 25
            Layout.preferredHeight: 25
            Layout.preferredWidth: 25

            IconClose {
                anchors.fill: parent
                width: parent.width
                height: parent.height
            }

            onClicked: {
                root.invokeClose()
            }
        }
    }
}
