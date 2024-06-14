import QtQuick

Canvas {
    id: customRectangle
    width: 200
    height: 200
    anchors.centerIn: parent

    property int topLeftRadius: 10
    property int topRightRadius: 10
    property int bottomRightRadius: 10
    property int bottomLeftRadius: 10
    property int borderWidth: 0
    property color background: "blue"
    property color borderColor: "blue"

    onPaint: {
        var ctx = getContext("2d")

        var width = customRectangle.width
        var height = customRectangle.height

        ctx.clearRect(0, 0, width, height)

        // Begin custom path for rounded rectangle
        ctx.beginPath()
        ctx.moveTo(topLeftRadius, 0)
        ctx.lineTo(width - topRightRadius, 0)
        ctx.arcTo(width, 0, width, topRightRadius, topRightRadius)
        ctx.lineTo(width, height - bottomRightRadius)
        ctx.arcTo(width, height, width - bottomRightRadius, height,
                  bottomRightRadius)
        ctx.lineTo(bottomLeftRadius, height)
        ctx.arcTo(0, height, 0, height - bottomLeftRadius, bottomLeftRadius)
        ctx.lineTo(0, topLeftRadius)
        ctx.arcTo(0, 0, topLeftRadius, 0, topLeftRadius)
        ctx.closePath()

        ctx.fillStyle = background
        ctx.fill()

        if (borderWidth > 0) {
            ctx.lineWidth = borderWidth
            ctx.strokeStyle = borderColor
            ctx.stroke()
        }
    }
}
