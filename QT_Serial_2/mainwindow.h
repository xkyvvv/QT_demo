#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "myChartView.h"
#include <QMainWindow>
#include <QtWidgets\QtWidgets> //包含QtWidgets头文件
#include "serial.h"
#include <QtCharts\QtCharts>

#include "serialWidget.h"
#include "chartWidget.h"
#include "FFT_IFFTWidget.h"


class MyMainWindow:public QMainWindow //定义一个MyMainWindow类，继承自QMainWindow窗口类
{
    Q_OBJECT      /////////////////加入这个才能使用Qt的信号和槽机制！！！！
    public:
     MyMainWindow(QWidget *parent = 0); //构造函数，参数是父窗体指针，默认是0，即没有父窗口

    private:
        Serial* m_serial = new Serial;
        QTabWidget *TabWidget = new QTabWidget(this);    //选项卡窗口
        serialWidget *mySerialWidget = new serialWidget(this,m_serial);
        chartWidget *myChartWidget = new chartWidget(this,m_serial);
        FFT_IFFTWidget *myFFT_IFFTWidget = new FFT_IFFTWidget;
};


#endif // MAINWINDOW_H
