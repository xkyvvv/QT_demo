#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QStringList>
#include <QDebug>
#include <QPushButton>
using namespace std;
class QMyLabel:public QLabel{
    Q_OBJECT
public slots:
    void rsetText(QTableWidgetItem * item);
};
void QMyLabel::rsetText(QTableWidgetItem * item){
    this->setText(item->text());
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //创建一个窗口，作为输入框和列表框的父窗口
    QWidget widget;
    //设置窗口的标题
    widget.setWindowTitle("QTableWidget控件");
    //自定义窗口的大小
    widget.resize(900,500);
    //在 widget 窗口中添加一个 4 行 3 列的表格
    QTableWidget TableWidget(4,3,&widget);
    //自定义表格的尺寸和字体大小
    TableWidget.resize(900,350);
    TableWidget.setFont(QFont("宋体",20));
    //设置表格中每一行的表头
    TableWidget.setHorizontalHeaderLabels(QStringList() << "教程" << "网址" << "状态");
    //设置表格数据区内的所有单元格都不允许编辑
    TableWidget.setEditTriggers(QAbstractItemView::NoEditTriggers);
    //设置表格中每一行的内容
    TableWidget.setItem(0,0,new QTableWidgetItem("C语言教程"));
    TableWidget.setItem(0,1,new QTableWidgetItem("http://c.biancheng.net/c/"));
    TableWidget.setItem(0,2,new QTableWidgetItem("已更新完毕"));
    TableWidget.setItem(1,0,new QTableWidgetItem("Qt教程"));
    TableWidget.setItem(1,1,new QTableWidgetItem("http://c.biancheng.net/qt/"));
    TableWidget.setItem(1,2,new QTableWidgetItem("正在更新"));
    TableWidget.setItem(2,0,new QTableWidgetItem("C++教程"));
    TableWidget.setItem(2,1,new QTableWidgetItem("http://c.biancheng.net/cplus/"));
    TableWidget.setItem(2,2,new QTableWidgetItem("已更新完毕"));
    //向 widget 窗口中添加一个文本框
    QMyLabel lab;
    lab.setText("选中单元格");
    lab.setParent(&widget);
    //自定义文本框的尺寸和位置
    lab.resize(900,150);
    lab.move(0,350);
    lab.setAlignment(Qt::AlignCenter);
    lab.setFont(QFont("宋体",16));
    widget.show();
    //为表格和文本框之间建立关联，当用户点击表格中某个单元格时，文本框显示单元格内的文本内容。
    QObject::connect(&TableWidget,&QTableWidget::itemClicked,&lab,&QMyLabel::rsetText);
    return a.exec();
}
//QMyLabel类的定义应该放到 .h 文件中，本例中将其写到 main.cpp 中，程序最后需要添加 #include "当前源文件名.moc" 语句，否则无法通过编译。
#include "main.moc"
