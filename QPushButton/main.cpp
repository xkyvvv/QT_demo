#include <QApplication>
#include <QWidget>
#include <QPushButton>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget widget;
    //设置 widget 窗口的标题
    widget.setWindowTitle("QWidget窗口");
    //创建一个按钮，并内嵌到 widget 窗口中
    QPushButton but("QPushButton按钮",&widget);
    //按钮的位置位于距 widget 窗口左上角 (100,100) 的位置
    but.move(100,100);
    //设置按钮上文字的大小。
    but.setStyleSheet("QPushButton{font:20px;}");
    //调整按钮的尺寸
    but.resize(200,200);
    //建立信息和槽，当用户点击并释放按钮后，该按钮隐藏。
    QObject::connect(&but,&QPushButton::clicked,&but,&QPushButton::hide);
    widget.show();
    return a.exec();
}
