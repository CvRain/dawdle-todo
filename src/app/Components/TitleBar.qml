import QtQuick
import QtQuick.Layouts

Item {
    id: root
    implicitWidth: 640
    implicitHeight: 180

    ColumnLayout {
        id: leftContent
        width: root.width / 2 - 5
        height: root.height
        anchors.left: parent.left
        anchors.leftMargin: 5

        Rectangle {
            id: testRect1
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "red"
        }
    }
    ColumnLayout {
        id: rightContent
        width: root.width / 2 - 5
        height: root.height
        anchors.right: parent.right
        anchors.rightMargin: 5

        Rectangle {
            id: testRect2
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "blue"
        }
    }
}
