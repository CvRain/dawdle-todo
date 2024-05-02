import QtQuick 2.0
import Theme.Catppunccin.Latte

Item {
    id: root
    width: 400
    height: 200

    Rectangle {
        anchors.fill: parent
        width: parent.width
        height: parent.height
        color: latte.Mantle
    }

    Latte {
        id: latte
    }
}
