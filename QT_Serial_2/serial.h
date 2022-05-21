#ifndef SERIAL_H
#define SERIAL_H

#include <QObject>
#include <QtSerialPort/QSerialPort>//提供串口功能
#include <QtSerialPort/QSerialPortInfo>//系统串口访问功能
#include <QMessageBox>
#include <QDebug>


class Serial:public QObject // 要继承QObject，才能使用 connect() 函数
{
    Q_OBJECT
public:

    Serial();
    QStringList scanSerial(); // 扫描可用串口
    bool open(QString serialName, int baudRate,int dataBits,QString parityBits,QString stopBits);
    void close(); // 关闭串口
    void sendData(QByteArray &sendData); // 发送数据给下位机
    QByteArray getReadBuf(); // 获得读取数据缓冲区
    void clearReadBuf(); // 清除读取数据缓冲区
    QByteArray hexStringToByteArray(QString HexString); // 将16进制字符串转换为对应的字节序列

signals:
    void readSignal(); // 当下位机中有数据发送过来时就会触发这个信号，以提示其它类对象

public slots:
    void readData(); // 读取下位机发来数据

private:
    QSerialPort *m_serialPort; // 实例化一个指向串口的指针，可以用于访问串口
    QByteArray m_readBuf; // 存储下位机发来数据的缓冲区
};

/******************************************************************************************/


#endif // SERIAL_H
