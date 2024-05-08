import QtQuick 2.0
import QtQuick.Controls
import Theme.Catppunccin.Latte

Menu {
    property Window sourceWindow

    signal invokeNewTodo

    id: root
    width: 80
    height: 100

    background: Rectangle {
        color: latte.Base
        border.color: latte.Rosewater
        radius: 5
    }

    HomeMenuItem {
        itemText: qsTr("new")
        onItemClick: {
            invokeNewTodo()
        }
    }

    HomeMenuItem {
        itemText: qsTr("setting")
    }

    MenuSeparator {}

    HomeMenuItem {
        itemText: qsTr("exit")
        onItemClick: {
            sourceWindow.close()
        }
    }

    Latte {
        id: latte
    }
}
