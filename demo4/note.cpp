/*
    鼠标事件:
        ① mousePressEvent
        ② mouseReleaseEvent
        ③ mouseMoveEvent
            注意：鼠标的坐标中的x或者y，只要发生至少1的移动，都会触发鼠标移动事件

    鼠标事件对象 QMouseEvent

    鼠标事件需要完成的功能:
        通过鼠标事件对象获取当前鼠标的坐标
            1:pos() 以父控件左上角为坐标原点，以QPoint的形式返回鼠标的坐标信息
                QPoint里面的x,y不支持浮点数
            2:globPos() 以QT程序的左上角为坐标原点，以QPoint的形式返回鼠标的坐标信息
            3:localPos() 以父控件左上角为坐标原点，以QPointF的形式返回鼠标的坐标信息
                QPointF里面的x，y是支持浮点数的
        一般都用pos

        鼠标事件用途很多:
            ① 封装自定义的 按钮模块
            ② 做窗口拖动功能
            ③ 配合绘图事件做一个绘图软件
*/
