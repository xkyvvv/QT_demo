//main.cpp
#include <QApplication>
#include <QWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QAbstractButton>
QPushButton* agreeBut;
QPushButton* disagreeBut;
class MyWidget:public QWidget{
    Q_OBJECT
public slots:
    void buttonClicked(QAbstractButton * butClicked);
};
void MyWidget::buttonClicked(QAbstractButton * butClicked){
    if(butClicked == (QAbstractButton*)disagreeBut){
        this->close();
    }
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //创建主窗口
    MyWidget myWidget;
    myWidget.setWindowTitle("主窗口");
    myWidget.resize(400,300);
    //创建消息框
    QMessageBox MyBox(QMessageBox::Question,"","");
    MyBox.setParent(&myWidget);
    //设置消息框的属性为对话框，它会是一个独立的窗口
    MyBox.setWindowFlags(Qt::Dialog);
    MyBox.setWindowTitle("协议");
    MyBox.setText("使用本产品，请您严格遵守xxx规定！");
    //自定义两个按钮
    agreeBut = MyBox.addButton("同意", QMessageBox::AcceptRole);
    disagreeBut = MyBox.addButton("拒绝", QMessageBox::RejectRole);
    myWidget.show();
    //添加信号和槽，监听用户点击的按钮，如果用户拒绝，则主窗口随之关闭。
    QObject::connect(&MyBox,&QMessageBox::buttonClicked,&myWidget,&MyWidget::buttonClicked);
    MyBox.exec();
    return a.exec();
}
//MyWidget类的定义应该放到 .h 文件中，本例中将其写到 main.cpp 中，程序最后需要添加 #include "当前源文件名.moc" 语句，否则无法通过编译。
#include "main.moc"
