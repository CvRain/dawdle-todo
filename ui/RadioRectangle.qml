import QtQuick
import QtQuick.Controls

Item{
    property color fillColor: "#881e1e2e"
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

        signal radioChanged()
        signal changeRadioStatus(bool isFinished)

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
                indicator.visible = !indicator.visible
                changeRadioStatus(indicator.visible)
                radioChanged()
            }
        }
    }

}
