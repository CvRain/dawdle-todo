import QtQuick
import QtQuick.Controls

Item{
    property color fillColor: "#1e1e2e"
    property color strokeColor: "#323244"
    width: parent.width
    height: width
    
    Rectangle{
        id: radio
        width: parent.width
        height: parent.height
        anchors.fill: parent
        border.color: strokeColor
        radius: width / 2

        Rectangle{
            id: indicator
            width: 10
            height: 10
            color: strokeColor
            radius: 45
            anchors.centerIn: parent
        }

    }

}