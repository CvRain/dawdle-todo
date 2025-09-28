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
        
        // 绘制最大化图标（一个矩形框）
        ctx.beginPath();
        ctx.rect(4, 4, 8, 8);
        ctx.stroke();
    }
}