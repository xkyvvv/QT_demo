#ifndef CHARTWIDGET_H
#define CHARTWIDGET_H

#include <QtWidgets\QtWidgets> //包含QtWidgets头文件
#include "myChartView.h"
#include <QtCharts\QtCharts>
#include "serial.h"

class chartWidget:public QWidget
{
    Q_OBJECT /////////////////加入这个才能使用Qt的信号和槽机制！！！！
public:
    chartWidget(QWidget *parent = 0,Serial *m_serial_t = nullptr); //构造函数
    void chartModeQComBoxChanged();    //绘图模式
    void saveWaveQPushButtonClicked(); //保存
    void openFileQPushButtonClicked(); //打开文件
    void clearDataQPushButtonClicked();  //清除数据
    void saveFileQPushButtonClicked();   //保存数据为文件
    void clearWaveQPushButtonClicked();  //清除波形
    void stopDisplayQCheckBoxChanged();  //停止显示
    void hexDisplayQCheckBoxChanged();  //hex
    void asciiDisplayQCheckBoxChanged();  //ascii
private slots:
     void readSerialData();
private:
    Serial *m_serial ; // 自定义串口类对象指针
    //QWidget *widgetWaveDisplay = new QWidget(this);
    QLineSeries *lineSeries = new QLineSeries();//创建折线序列
    QChart *chart = new QChart();//创建图表chart
    QList<QPointF> data;//存放QPointF类型数据的列表data

    QTextEdit* receiveTextEdit = new QTextEdit;  //文本框
    QGroupBox *waveSettingGroupBox = new QGroupBox;
    QGroupBox *recSettingGroupBox = new QGroupBox;
    QComboBox* chartModeComBox = new QComboBox;   //绘图模式：点、线、点+线
    QPushButton* saveWavePushButton = new QPushButton;  //保存波形按钮
    QPushButton* openFilePushButton = new QPushButton;  //打开文件按钮
    QPushButton* clearWavePushButton = new QPushButton; //清除波形
    QLabel* chartModeLabel = new QLabel;     //绘图模式

    QCheckBox *hexDisplayCheckBox = new QCheckBox;   //hex
    QCheckBox *asciiDisplayCheckBox = new QCheckBox;  //ascii
    QPushButton* saveFilePushButton = new QPushButton;   //保存数据到文件
    QPushButton* clearDataPushButton = new QPushButton;  //清除数据
    ChartView *chartView = new ChartView(chart);

    QScatterSeries *scatterSeries = new QScatterSeries(); //创建散点序列
    QCheckBox* stopDisplayQCheckBox = new QCheckBox;
    int chartMode = 0;  // 0:线  1：点   2：点+线
    bool stopDisplay = false;    //停止显示
    bool ASCIIDisp = true;  // 0:ASCII   1:HEX
    int bufIndex = 0;
    float buf[1024];
};

#endif // CHARTWIDGET_H
