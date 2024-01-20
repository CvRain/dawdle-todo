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
            width: parent.width * 0.6
            height: parent.height * 0.6
            color: fillColor
            radius: width / 2
            anchors.centerIn: parent
            visible: false
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                smoothOpacity.start()
                indicator.visible = !indicator.visible
            }
        }
    }

    NumberAnimation {
        id: smoothOpacity
        target: indicator
        property: "opacity"
        duration: 1000
        easing.type: Easing.InOutQuad
        from: indicator.opacity
        to: indicator.visible ? 0 : 1
    }


}
