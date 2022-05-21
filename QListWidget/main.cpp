//main.cpp
#include <QApplication>
#include <QWidget>
#include <QListWidget>
#include <QLabel>
#include <QListWidgetItem>
using namespace std;
class QMyLabel:public QLabel{
    Q_OBJECT
public slots:
    void rsetText(QListWidgetItem *item);
};
void QMyLabel::rsetText(QListWidgetItem *item){
    this->setText(item->text());
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //创建一个窗口，作为输入框的父窗口
    QWidget widget;
    //设置窗口的标题
    widget.setWindowTitle("QWidget窗口");
    widget.resize(500,500);
    QListWidget listWidget(&widget);
    listWidget.resize(500,400);
    listWidget.setFont(QFont("宋体",14));
    listWidget.addItem("C语言中文网");
    listWidget.addItem("http://c.biancheng.net");
    listWidget.addItem(new QListWidgetItem("Qt教程"));
    QMyLabel print;
    print.setText("选中内容");
    print.setParent(&widget);
    print.resize(500,100);
    print.move(0,400);
    print.setAlignment(Qt::AlignCenter);
    QObject::connect(&listWidget,&QListWidget::itemClicked,&print,&QMyLabel::rsetText);
    widget.show();
    return a.exec();
}
//QMyLabel类的定义应该放到 .h 文件中，本例中将其写到 main.cpp 中，程序最后需要添加 #include "当前源文件名.moc" 语句，否则无法通过编译。
#include "main.moc"
