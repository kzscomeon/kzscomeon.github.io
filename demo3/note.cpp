// 事件过滤器：
/*

    什么是事件过滤器：
        一般情况下，键盘事件，鼠标事件，他们都是发生在父控件里面的，子控件是接收不到父控件的键盘事件，鼠标事件的(鼠标事件也有特殊的地方，到时候再说)
        如果我们想要子控件接收到键盘事件或者鼠标时间的话，就需要让父控件，将键盘事件或者鼠标事件派发给子控件
    但是这个派发事件的操作，没得选。要派发，则所有的事件一起派发，要不派发，则所有事件一起不派发
    所以，这个时候，我们需要在子控件里面写一个事件过滤器，目的在于过滤掉我们不要的事件，仅仅留下子控件需要接受的事件就好了

    在上述描述当中，有几个问题需要解决
    ① 我们需要验证一下，子控件是否真的无法接受到键盘事件，或者鼠标事件
        首先，我们自己写一个控件 label，继承自QLabel
        写好之后，还有一个问题
            ui界面中的label，和我们自己写的label类，完全没关系
        所以我们要把ui界面中的label对象，他的类型，变成我们自己写的label类

        这个操作使用 "提升为" 功能
        右键ui界面中的目标控件 -> 提升为 -> 在"提升的类名称"后面，写上我们自己写的类名 -> 勾选"全局包含" -> 点击 "提升" -> 点击 "确认"

    注意： "提升为" 这个功能很重要
        他允许我们能够深度的自定义 ui界面中的任何一个控件

    ② 如何派发事件：在父控件里面，安装一下事件过滤器，传入子控件地址，就可以向目标子控件派发事件了
        installEventFilter(QObject* child)
    ③ 子控件如何过滤器事件
        子控件重写事件过滤器函数:
        public 里面的 virtual 方法
        virtual bool eventFilter(QObject *watched, QEvent *event)
            watched:事件派发方指针
            event：所派发的事件的指针
            返回值:  返回true表示不再接受下一次事件的派发
                    返回false表示依旧需要接受下一次事件的派发
*/
