 #include "mainwindow.h"

//定义构造函数，参数是父窗体指针，先调用基类构造函数QMainWindow(parent)
MyMainWindow::MyMainWindow(QWidget *parent):QMainWindow(parent)
{
    this->setWindowTitle("调试助手"); //设置窗体的标题
    this->resize(960,640); 		//变更窗体尺寸
    this->setCentralWidget(TabWidget);

    TabWidget->addTab(mySerialWidget, "串口调试");
    TabWidget->addTab(myChartWidget, "波形显示");
    TabWidget->addTab(myFFT_IFFTWidget, "FFT/IFFT");
}





