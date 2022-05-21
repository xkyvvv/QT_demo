#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //创建一个QLabel对象
    this->lab = new QLabel("Hello World!", this);
}

MainWindow::~MainWindow()
{

}
