import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Theme.Catppuccin.Theme
import Theme.Catppuccin.Palette

import "../components"

Item {
    property string titleText: "dawdle todo"
    property Window distWindow

    signal titleIconClicked
    signal closeButtonClicked
    signal minButtonClicked
    signal maxButtonClicked
    signal themeButtonClicked(bool isDark)

    id: root
    width: 450
    height: 40

    Rectangle {
        id: titleBar
        width: parent.width
        height: parent.height
        color: catppuccinTheme.crust()

        MouseArea {
            id: dragArea
            anchors.fill: parent
            property int mouseXOffset: 0
            property int mouseYOffset: 0
            property bool dragging: false

            Connections {
                target: dragArea
                function onPressed(mouse) {
                    // 记录点击时鼠标位置相对于窗口的位置
                    dragArea.mouseXOffset = mouse.x
                    dragArea.mouseYOffset = mouse.y
                    dragArea.dragging = true
                    // console.log(mouse.x)
                    // console.log(mouse.y)
                }
                function onPositionChanged(mouse) {
                    // 如果鼠标已按下，则根据鼠标的移动来移动窗口
                    if (dragArea.dragging) {
                        distWindow.x += mouse.x - dragArea.mouseXOffset
                        distWindow.y += mouse.y - dragArea.mouseYOffset
                        // console.log(mouse.x)
                        // console.log(mouse.y)
                    }
                }
                function onReleased() {
                    // 鼠标释放后停止拖动
                    dragArea.dragging = false
                }
            }
        }

        Row {
            id: leftPart
            width: parent.width / 2
            height: parent.height
            spacing: 5

            TitleButton {
                id: iconContainer
                height: titleBar.height * 0.6
                width: titleBar.height * 0.6
                iconPath: "qrc:/res/icons/home.svg"
                anchors {
                    verticalCenter: parent.verticalCenter
                }
                hoverColor: catppuccinTheme.overlay2()
                onIconClicked: titleIconClicked()

                Connections {
                    target: iconContainer
                    function titleIconClicked() {
                        titleIconClicked()
                    }
                }
            }

            Text {
                id: title
                text: titleText
                font.weight: Font.Bold
                width: parent.width / 2
                height: parent.heighte
                color: catppuccinTheme.subtext1()
                verticalAlignment: Text.AlignVCenter
                clip: true
                horizontalAlignment: Text.AlignLeft
                anchors {
                    verticalCenter: parent.verticalCenter
                }
            }
        }

        RowLayout {
            id: rightPart
            width: titleBar.height * 0.4 * 4
            height: parent.height
            spacing: 5
            anchors.right: titleBar.right
            anchors.rightMargin: 10
            layoutDirection: Qt.RightToLeft
            Layout.alignment: Qt.RightToLeft

            TitleButton {
                id: exitWindow
                width: titleBar.height * 0.39
                height: titleBar.height * 0.39
                iconPath: "qrc:/res/icons/exit.svg"
                hoverColor: catppuccinTheme.overlay2()
                onIconClicked: closeButtonClicked()

                Connections {
                    target: exitWindow
                    function onIconClicked() {
                        console.log("WindowTitle::CloseButton::clicked")
                        closeButtonClicked()
                        distWindow.close()
                    }
                }
            }

            TitleButton {
                id: maxWindow
                width: titleBar.height * 0.4
                height: titleBar.height * 0.4
                iconPath: "qrc:/res/icons/max.svg"
                hoverColor: catppuccinTheme.overlay2()
                onIconClicked: maxButtonClicked()

                Connections {
                    target: maxWindow
                    function onIconClicked() {
                        console.log("WindowTitle::MaxButton::clicked")
                        maxButtonClicked()
                        if (distWindow.Maximized) {
                            distWindow.Maximized = false
                            distWindow.showNormal()
                            //distWindow.setGeometry(0, 0, 600, 400)
                        } else {
                            distWindow.showMaximized()
                        }
                    }
                }
            }

            TitleButton {
                id: minWindow
                width: titleBar.height * 0.4
                height: titleBar.height * 0.4
                iconPath: "qrc:/res/icons/min.svg"
                hoverColor: catppuccinTheme.overlay2()
                onIconClicked: minButtonClicked()

                Connections {
                    target: minWindow
                    function onIconClicked() {
                        console.log("WindowTitle::MinButton::clicked")
                        minButtonClicked()
                        distWindow.showMinimized()
                    }
                }
            }

            TitleButton {
                id: themeButton
                width: titleBar.height * 0.45
                height: titleBar.height * 0.45
                iconPath: "qrc:/res/icons/theme-dark.svg"
                hoverColor: catppuccinTheme.overlay2()
                property bool isDarkMode: true
                onIconClicked: {
                    isDarkMode = !isDarkMode
                    iconPath = isDarkMode ? "qrc:/res/icons/theme-dark.svg" : "qrc:/res/icons/theme-light.svg"
                    themeButtonClicked(isDarkMode)
                    switchTheme(isDarkMode)
                }

                function switchTheme(isDarkMode) {
                    if (isDarkMode) {
                        catppuccinTheme.switch_theme(CatppuccinType.Latte)
                    } else {
                        catppuccinTheme.switch_theme(CatppuccinType.Mocha)
                    }
                }
            }
        }
    }

    CatppuccinTheme {
        id: catppuccinTheme

        onThemeChanged: {
            colorAnimation.target = titleBar
            colorAnimation.from = titleBar.color
            colorAnimation.to = catppuccinTheme.crust()
            colorAnimation.start()
        }
    }

    ColorAnimation {
        id: colorAnimation
        target: titleBar
        duration: 400
        properties: "color"
        easing.type: Easing.InOutQuad
    }
}
