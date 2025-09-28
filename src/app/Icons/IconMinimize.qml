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
        
        // 绘制最小化图标（一条横线）
        ctx.beginPath();
        ctx.moveTo(4, 8);
        ctx.lineTo(12, 8);
        ctx.stroke();
    }
}