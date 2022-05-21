#include <QApplication>
#include <QWidget>
#include <QLineEdit>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //创建一个窗口，作为输入框的父窗口
    QWidget widget;
    //设置窗口的标题
    widget.setWindowTitle("QWidget窗口");

    //接下来，分别创建两个输入框，用于让用户分别输入账号和密码
    //创建账号输入框
    QLineEdit lineEdit(&widget);
    //指定输入框位于父窗口中的位置
    lineEdit.move(100,100);
    //设置提示信息
    lineEdit.setPlaceholderText("请输入账号...");
    //让输入框显示“一键清除”按钮
    lineEdit.setClearButtonEnabled(true);

    //创建密码输入框
    QLineEdit lineEditPass(&widget);
    lineEditPass.setPlaceholderText("请输入密码...");
    lineEditPass.move(100,150);
    //指定文本显示方式，保护用户账号安全
    lineEditPass.setEchoMode(QLineEdit::Password);

    //指定窗口的尺寸和显示文字的大小
    widget.resize(500,300);
    widget.setFont(QFont("宋体",16));
    widget.show();
    return a.exec();
}
