#include <QApplication>
#include <QLabel>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //创建一个文本框
    QLabel lab;
    //设置文本框内容居中显示
    lab.setAlignment(Qt::AlignCenter);
    //设置文本框的坐标和尺寸
    lab.setGeometry(100,100,400,400);
    //设置文本框的外观，包括字体的大小和颜色、按钮的背景色
    lab.setStyleSheet("QLabel{font:30px;color:red;background-color:rgb(f9,f9,f9);}");
    //设置文本框要显示超链接内容
    lab.setText("<a href=\"http://c.biancheng.net\">C语言中文网");
    //当用户鼠标位于文本框上时，显示提示内容
    lab.setToolTip("点击超链接显示URL");
    //提示内容显示 1 秒
    lab.setToolTipDuration(1000);
    //为文本框设置信号和槽，当用户点击超链接时，将文本框内容改为超链接的 URL
    QObject::connect(&lab,&QLabel::linkActivated,&lab,&QLabel::setText);
    //程序运行后，文本框显示
    lab.show();
    return a.exec();
}
