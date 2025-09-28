import QtQuick

Rectangle {
    id: button

    signal clicked
    signal entered
    signal exited

    color: "#acb0be"
    border.color: "#acb0be"
    radius: 5

    Behavior on color {
        id: buttonAnimation

        ColorAnimation {
            duration: 100
            easing.type: Easing.InOutQuad
        }
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true

        onClicked: {
            button.clicked()
        }
        onEntered: {
            button.entered()
            button.color = "#ccd0da"
            button.border.color = "#acb0be"
        }
        onExited: {
            button.exited()
            button.color = "#acb0be"
            button.border.color = "#ccd0da"
        }
    }
}
