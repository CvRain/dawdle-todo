import QtQuick

Item {
    property color defaultColor: "#871e1e2e" //the shitting format of color in QML is "AARRGGBB"
    property color defaultFontColor: "#DDFFFFFF"
    width: 640
    height: 120
    id: root
    Rectangle{
        id: mainView
        color: defaultColor
        radius: 20
        anchors.fill: root

        TextInput{
            id: banner
            anchors.top: parent.top
            anchors.centerIn: parent

            color: defaultFontColor
            text: "Hello world!"
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
        height: 3
        width: mainView.width - 10
        color: defaultFontColor
        radius: 25

        anchors.top: mainView.bottom
        anchors.topMargin: 7
        anchors.horizontalCenter: mainView.horizontalCenter

    }
}
