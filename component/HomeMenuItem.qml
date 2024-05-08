import QtQuick 2.0
import QtQuick.Controls

MenuItem {
    property string itemText: "default text"
    signal itemClick(var mouse)

    FontLoader {
        id: nerdFont
        source: "qrc:/font/CascadiaCode/CaskaydiaCoveNerdFontMono-Regular.ttf"
    }
    contentItem: Text {
        text: itemText
        color: latte.DefaultText
        font {
            family: nerdFont.name
            pointSize: 12
            bold: true
        }
        MouseArea {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true
            onEntered: parent.color = latte.Rosewater
            onExited: parent.color = latte.DefaultText
        }
    }
    Connections {
        target: mouseArea
        function onClicked(mouse) {
            itemClick(mouse)
        }
    }
}
