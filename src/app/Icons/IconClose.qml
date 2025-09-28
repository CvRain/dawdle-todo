import QtQuick

Canvas {
    id: root

    width: 16
    height: 16

    onPaint: {
        var ctx = getContext("2d");
        ctx.fillStyle = "white";
        ctx.strokeStyle = "white";
        ctx.lineWidth = 2;
        
        // 绘制 X 形状
        ctx.beginPath();
        ctx.moveTo(4, 4);
        ctx.lineTo(12, 12);
        ctx.stroke();
        
        ctx.beginPath();
        ctx.moveTo(12, 4);
        ctx.lineTo(4, 12);
        ctx.stroke();
    }
}