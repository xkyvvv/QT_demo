#ifndef SERIALWIDGET_H
#define SERIALWIDGET_H

#include <QtWidgets\QtWidgets> //包含QtWidgets头文件
#include <QtCharts\QtCharts>
#include "serial.h"

class serialWidget:public QWidget
{
    Q_OBJECT /////////////////加入这个才能使用Qt的信号和槽机制！！！！
public:
    //构造函数，两个参数
   serialWidget(QWidget *parent = 0,Serial *m_serial_t = nullptr);
   //串口配置
   void openPortQPushButtonClicked();  //打开串口按钮点击相应函数
   void serialPortUpdate();           //更新串口号
   int getBaudRate();              //获取波特率
   //接收区
   void hexReceiveQCheckBoxChanged(); //hex
   void asciiReceiveQCheckBoxChanged();  //ascii
   void stopDispCheckBoxChanged();    //停止显示
   void logModeCheckBoxChanged();    //日志模式
   void clearReceiveAeraQPushButtonClicked();  //清除接收区
   void saveReceiveAreaQPushBuutonClicked();  //保存接收区
   //发送区
   void sendDataPushButtonClicked();  //发送按钮
   void hexSendCheckBoxChanged();    //hex
   void asciiSendCheckBoxChanged();  //ascii
   void autoSendCheckBoxChanged();   //自动发送
   void spinBoxValueChanged();      //自动发送周期

private slots:
     void readSerialData();   //读取数据的槽函数

private:
   Serial *m_serial; // 定义串口类对象指针
   //文本框
   QTextEdit* receiveTextEdit = new QTextEdit(this);   //接收区的文本框
   QTextEdit* sendTextEdit = new QTextEdit(this);      //发送区的文本框
   //组合框
   QGroupBox *serialSettingQGroupBox = new QGroupBox;   //串口配置的组合框
   QGroupBox *receiveSettingQGroupBox = new QGroupBox;   //接收区组合框
   QGroupBox *snedSeetingQGroupBox = new QGroupBox;    //发送区组合框
   //标签
   QLabel* serialQLabel = new QLabel;    //串口
   QLabel* baudRateQLabel = new QLabel;  //波特率
   QLabel* dataBitsQLabel = new QLabel;  //数据位
   QLabel* stopBitQLabel = new QLabel;   //停止位
   QLabel* parityBitQLabel = new QLabel;  //校验位
   //下拉框
   QComboBox* serialQComboBox = new QComboBox;    //串口
   QComboBox* baudRateQComboBox = new QComboBox;  //波特率
   QComboBox* dataBitsQComboBox = new QComboBox;  //数据位
   QComboBox* stopBitQComboBox = new QComboBox;  //停止位
   QComboBox* parityBitQComboBox = new QComboBox;  //校验位
   //按钮
   QPushButton* openSerialQButton = new QPushButton;  //打开串口
   //定时器
   QTimer timer;//定义一个定时器timer，用于更新串口
   QTimer autoSendDataTimer;  //自动重发
   //接收区  复选框
   QCheckBox *hexReceiveQCheckBox = new QCheckBox;  //hex
   QCheckBox *asciiReceiveQCheckBox = new QCheckBox;  //ascii
   QCheckBox *stopDisplayQCheckBox = new QCheckBox;   //停止显示
   QCheckBox *logModeQCheckBox = new QCheckBox;    //日志模式
   //按钮
   QPushButton *clearReceiveAeraQPushButton = new QPushButton;  //清除接收区
   QPushButton *saveReceiveAeraQPushButton = new QPushButton;   //保存接收区
   //发送区
   QSpinBox *autoSendQSpinBox = new QSpinBox;  //自动重发
   QLabel *autoSendQLabel = new QLabel;  //自动重发标签
   QCheckBox *hexSendQCheckBox = new QCheckBox;  //hex
   QCheckBox *asciiSendQCheckBox = new QCheckBox;  //ascii
   QCheckBox *autoSendQCheckBox = new QCheckBox;  //自动重发
   QPushButton *sendDataQPushButton = new QPushButton;  //发送
   //标志位
   bool ASCIIDisp = true;  // ascii 和 hex
   bool ASCIISend = true;   //ascii和hex
   bool stopDisplay = false;  //停止显示
   bool logMode = false;
};

#endif // SERIALWIDGET_H
