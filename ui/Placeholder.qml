import QtQuick

Item {
    property color defaultColor: "#871e1e2e" //the shitting format of color in QML is "AARRGGBB"
    property color defaultFontColor: "#DDFFFFFF"
    width: 640
    height: 120
    id: root

    MouseArea {
        anchors.fill: parent
        onEntered: banner.color = Qt.darker(defaultColor)
        onExited: banner.color = defaultFontColor

        Rectangle{
            id: mainView
            color: defaultColor
            radius: 20
            anchors.fill: parent

            TextInput{
                id: banner
                anchors.top: parent.top
                anchors.centerIn: parent

                color: defaultFontColor
                text: "君子终日乾乾，夕惕若厉，无咎"
                font.pixelSize: 24
                horizontalAlignment: Text.AlignHCenter
            }
            Text{
                id: dateView
                anchors.top: banner.bottom
                anchors.right: banner.right
                anchors.rightMargin: -20

                color: defaultFontColor
                width: parent.width
                text: "2024-1-14"
                horizontalAlignment: Text.AlignRight
            }

        }

        Rectangle{
            id: bannerLine
            height: 3
            width: mainView.width
            color: defaultFontColor

            anchors.top: mainView.bottom
            anchors.topMargin: 5
            
        }
    }
}
