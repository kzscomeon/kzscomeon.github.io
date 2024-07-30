// 事件概述
/*
    QT中的事件：事件本质上来说，还是函数
    只不过事件函数调用之后，不会立刻执行，而是会发送到QT的事件循环中，等待被执行
    QT中的事件，其实又分为2种:
        队列事件:信号和槽，都是队列事件
            show,hide,等等 这些其实都是队列事件
        系统事件：都是类当中的protected标签下的virtual函数
            鼠标事件， 键盘事件，绘图事件 等等

        关于事件循环:循环逻辑大致如下

        while(1){
            while(判断是否还有队列事件){
                执行所有队列事件
            }

            while(判断是否还有系统事件){
                执行所有的系统事件
            }

            while(判断是否还有队列事件){
                执行所有的队列事件
            }
        }

        为什么一次事件循环中，要执行2遍队列事件
            因为当我们重写系统事件的时候，仅仅是为这个系统事件追加新的功能，并不会改变系统事件本身拥有的行为
            那么在为系统事件追加新的功能的时候，可能会发送信号，可能会调用槽函数,从而导致系统事件可能派生出新的队列事件，所以我们要在系统事件执行完成之后，再清空一遍队列事件

        顺带一提：我们重写系统事件，但是不会改变系统事件的本身逻辑，而是追加新的逻辑，这种做法其实是设计模式:装饰器模式
*/

// 关闭事件
/*
    关闭事件可以由 点击窗口右上角的 x 符号调用
    也可以由槽函数 close() 调用
    关闭事件本身也是 protected 标签底下的 virtual 函数
        既然是protected底下的virtual函数，我们就可以去重写他
    注意 close()本身是个槽函数，不是关闭事件，close调用了关闭事件而已

    我们要自定义关闭事件的话，就必须 重写 virtual void closeEvent(QCloseEvent* ev);
        ev:管理关闭事件当中，可能会用到的所有的数据或者方法的对象
        例如：我们可以通过ev去忽略或接受关闭事件

        又例如：在键盘事件里面，我们可以通过键盘事件的ev对象，去获取键盘敲击的数据
        又例如：在鼠标事件里面，我们可以通过鼠标事件的ev对象，去获取鼠标当前的坐标位置

    以当前案例测试关闭事件之后，我们得到几个结论
        ① 无论我们如何重写关闭事件，只要关闭事件没有被忽略，那么关闭窗口这个操作，就都会被执行
        ② 关闭事件执行完成之后，才会执行析构函数

    关闭事件和隐藏事件有什么区别？
        当一个程序中有多个窗口的时候，最后一个显示的窗口，如果调用的是隐藏事件，则程序继续运行
                                                如果调用时关闭事件，则程序直接结束
        其实，关闭事件本身，也是通过调用隐藏事件，来 "关闭" 窗口的，只不过关闭事件会在 "关闭" 窗口之后，判断一下是否为最后一个可见窗口，如果是最后一个可见窗口的话，则程序直接结束。如果不是最后一个可见窗口的话，仅仅隐藏这个窗口而已
*/
