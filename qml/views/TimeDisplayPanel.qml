import QtQuick
import QtQuick.Controls
import Theme.Catppuccin.Theme
import Theme.Catppuccin.Palette
import Theme.Catppuccin.Color

import "../components"

MoveableWindow {
    id: root
    width: 200
    height: 200
    visible: true
    // bgColor: CatppuccinColor.Base
    // alpha: 0.6
    title: qsTr("dawdle-todo")
    color: "transparent"
    flags: Qt.WA_TranslucentBackground | Qt.FramelessWindowHint | Qt.WA_TranslucentBackground

    Rectangle {
        id: clock
        color: "transparent"
        width: parent.width
        height: parent.width - 30

        Canvas {
            id: clockCanvas
            anchors.fill: parent
            antialiasing: true //抗锯齿
            onPaint: {
                var ctx = getContext("2d")
                ctx.clearRect(0, 0, width, height)
                ctx.globalCompositeOperation = "source-over" // 设置合成模式
                drawClock(ctx)
            }

            Timer {
                interval: 1000
                running: true
                repeat: true
                onTriggered: clockCanvas.requestPaint()
            }
        }
    }

    Text {
        id: timeText
        color: theme.subtext0()
        font.pixelSize: Math.min(root.width * 0.1, root.height * 0.2)
        font.bold: true
        font.family: cascadiaCodeFont.name
        horizontalAlignment: Text.AlignHCenter
        width: parent.width
        height: parent.height - clock.height
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: clock.bottom
    }

    function drawClock(ctx) {
        var centerX = clockCanvas.width / 2
        var centerY = clockCanvas.height / 2
        var radius = Math.min(centerX, centerY) * 0.8

        // 绘制表盘
        ctx.beginPath()
        ctx.arc(centerX, centerY, radius, 0, 2 * Math.PI)
        ctx.strokeStyle = theme.rosewater()
        ctx.lineWidth = 8
        ctx.stroke()
        ctx.closePath()

        // 绘制时针
        var currentTime = new Date()
        var hour = currentTime.getHours()
        var minute = currentTime.getMinutes()
        var second = currentTime.getSeconds()
        var hourAngle = (hour % 12) * 30 * Math.PI / 180 + (minute * 6 * Math.PI / 180) / 12
        var hourHandLength = radius * 0.5
        ctx.beginPath()
        ctx.moveTo(centerX, centerY)
        ctx.lineTo(centerX + hourHandLength * Math.cos(hourAngle),
                   centerY + hourHandLength * Math.sin(hourAngle))
        ctx.strokeStyle = theme.rosewater()
        ctx.lineWidth = 10
        ctx.stroke()
        ctx.closePath()

        // 绘制分针
        var minuteAngle = minute * 6 * Math.PI / 180
        var minuteHandLength = radius * 0.6
        ctx.beginPath()
        ctx.moveTo(centerX, centerY)
        ctx.lineTo(centerX + minuteHandLength * Math.cos(minuteAngle),
                   centerY + minuteHandLength * Math.sin(minuteAngle))
        ctx.strokeStyle = theme.rosewater()
        ctx.lineWidth = 8
        ctx.stroke()
        ctx.closePath()

        // 绘制秒针
        var secondAngle = second * 6 * Math.PI / 180
        var secondHandLength = radius * 0.7
        ctx.beginPath()
        ctx.moveTo(centerX, centerY)
        ctx.lineTo(centerX + secondHandLength * Math.cos(secondAngle),
                   centerY + secondHandLength * Math.sin(secondAngle))
        ctx.strokeStyle = theme.rosewater()
        ctx.lineWidth = 4
        ctx.stroke()
        ctx.closePath()
    }

    Timer {
        interval: 1000
        running: true
        repeat: true
        onTriggered: {
            var currentDate = new Date()
            timeText.text = Qt.formatDateTime(currentDate, "hh:mm:ss")
        }
    }
    FontLoader {
        id: cascadiaCodeFont
        source: "qrc:/res/fonts/CascadiaCode/CaskaydiaCoveNerdFontMono-Regular.ttf"
    }
}
