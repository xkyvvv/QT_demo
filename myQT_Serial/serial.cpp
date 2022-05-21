#include "serial.h"
#include "ui_serial.h"

Serial::Serial(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Serial)
{
    ui->setupUi(this);

    /*----------user-----------*/
    //init 用户系统初始化
    system_init();
}

Serial::~Serial()
{
    delete ui;
}

/*---------------------------------------------------------------------
 *             funtion
 * --------------------------------------------------------------------*/
//用户系统初始化
void Serial::system_init()
{
    //port conifg
    ui->cmd_port_name->clear();
    //通过QSerialPortInfo查找可用串口
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        //将可用串口添加到端口显示框
        ui->cmd_port_name->addItem(info.portName());
    }

    //设置串口状态标签为红色 表示未连接状态
    ui->lab_status->setStyleSheet("color:red");
    //statusBar 状态栏显示端口状态 未连接
    QString sm = "%1 CLOSED";
    QString status = sm.arg(ui->cmd_port_name->currentText());
    ui->statusBar->showMessage(status);
    ui->statusBar->setStyleSheet("color:red");

    //timer 自动发送
    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,[=](){
        emit my_send_signals(true); //触发发送信号
    });

    QToolBar *toolBar = addToolBar("toolBar");
    QPushButton *btn_check = new QPushButton("检测串口",this);
    QPushButton *btn_open = new QPushButton("打开串口",this);
    QPushButton *btn_close = new QPushButton("关闭串口",this);
    QPushButton *btn_clear = new QPushButton("清空接收",this);
    QPushButton *btn_file = new QPushButton("打开文件",this);
    QPushButton *btn_log = new QPushButton("保存日志",this);
    toolBar->addWidget(btn_check);
    toolBar->addWidget(btn_open);
    toolBar->addWidget(btn_close);
    toolBar->addWidget(btn_clear);
    toolBar->addWidget(btn_file);
    toolBar->addWidget(btn_log);

    //connect
    //check port 检测通讯端口
    connect(btn_check,&QPushButton::clicked,this,&Serial::btn_serial_check);
    //open port 打开选择端口
    connect(btn_open,&QPushButton::clicked,this,&Serial::btn_open_port);
    //close port 关闭选择端口
    connect(btn_close,&QPushButton::clicked,this,&Serial::btn_close_port);
    //clear recevie 清除接收文本框的内容
    connect(btn_clear,&QPushButton::clicked,this,&Serial::btn_clear_rev);
    //打开发送文件
    connect(btn_file,&QPushButton::clicked,this,&Serial::btn_open_send_file);
    //保存接收日志
    connect(btn_log,&QPushButton::clicked,this,&Serial::btn_save_rev_log);

    //send data 发送按钮 触发发送信号
    connect(ui->btn_send,&QPushButton::clicked,[=](){
        emit my_send_signals(true);
    });
    //发送信号   发送槽函数
    connect(this,&Serial::my_send_signals,this,&Serial::btn_send_data);

    //receive data 串口数据接收完触发更新添加显示接收文本框
    connect(&global_port,&QSerialPort::readyRead,this,&Serial::receive_data);
}

//字符串转16进制
QByteArray Serial::QString2Hex(QString str)
{
    QByteArray senddata;
    int hexdata,lowhexdata;
    int hexdatalen = 0;
    int len = str.length();

    senddata.resize(len/2);
    char lstr,hstr;

    for(int i=0; i<len; )
    {
        hstr=str[i].toLatin1();
        if(hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        if(i >= len)
            break;
        lstr = str[i].toLatin1();
        hexdata = ConvertHexChar(hstr);
        lowhexdata = ConvertHexChar(lstr);
        if((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            hexdata = hexdata*16+lowhexdata;
        i++;
        senddata[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }
    senddata.resize(hexdatalen);
    return senddata;
}
//字符转16进制
char Serial::ConvertHexChar(char ch)
{
    if((ch >= '0') && (ch <= '9'))
        return ch-0x30;
    else if((ch >= 'A') && (ch <= 'F'))
        return ch-'A'+10;
    else if((ch >= 'a') && (ch <= 'f'))
        return ch-'a'+10;
    else return (-1);
}

/*---------------------------------------------------------------------
 *             slots
 * --------------------------------------------------------------------*/
//检测通讯端口槽函数
void Serial::btn_serial_check(bool)
{
    ui->cmd_port_name->clear();
    //通过QSerialPortInfo查找可用串口
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->cmd_port_name->addItem(info.portName());
    }
}

//打开选择端口槽函数
void Serial::btn_open_port(bool)
{
    //port name 设置端口
    global_port.setPortName(ui->cmd_port_name->currentText());
    //baud rate 设置波特率
    global_port.setBaudRate(ui->cmd_baud_rate->currentText().toInt());
    //parity 设置校验位
    switch (ui->cmd_parity->currentIndex()) {
    case 0:     //无校验
        global_port.setParity(QSerialPort::NoParity);
        break;
    case 1:     //偶校验
        global_port.setParity(QSerialPort::EvenParity);
        break;
    default:    //奇校验
        global_port.setParity(QSerialPort::OddParity);
        break;
    }

    //data bits 设置数据位
    switch (ui->cmd_data_bits->currentText().toInt()) {
    case 8:
        global_port.setDataBits(QSerialPort::Data8);
        break;
    case 7:
        global_port.setDataBits(QSerialPort::Data7);
        break;
    case 6:
        global_port.setDataBits(QSerialPort::Data6);
        break;
    default:
        global_port.setDataBits(QSerialPort::Data5);
        break;
    }

    //stop bits 设置停止位
    switch (ui->cmd_stop_bits->currentIndex()) {
    case 0:
        global_port.setStopBits(QSerialPort::OneStop);
        break;
    case 1:
        global_port.setStopBits(QSerialPort::OneAndHalfStop);
        break;
    default:
        global_port.setStopBits(QSerialPort::TwoStop);
        break;
    }

    //port open 打开选择端口
    bool ret = global_port.open(QIODevice::ReadWrite);

    if(ret){
        //打开成功更新状态
        ui->lab_status->setText("OPENED");
        //设置串口状态标签为绿色 表示已连接状态
        ui->lab_status->setStyleSheet("color:green");

        //statusBar 状态栏显示端口状态
        QString sm = "%1 OPENED, %2, 8, NONE, 1";
        QString status = sm.arg(global_port.portName()).arg(global_port.baudRate());
        ui->statusBar->showMessage(status);
        ui->statusBar->setStyleSheet("color:green");
    }
}

//关闭选择端口槽函数
void Serial::btn_close_port(bool)
{

    global_port.close();

    //关闭端口后显示状态
    ui->lab_status->setText("CLOSED");
    ui->lab_status->setStyleSheet("color:red");

    //statusBar 状态栏显示端口状态
    QString sm = "%1 CLOSED";
    QString status = sm.arg(global_port.portName());
    ui->statusBar->showMessage(status);
    ui->statusBar->setStyleSheet("color:red");
}

//发送数据槽函数
void Serial::btn_send_data(bool)
{
    QString data = ui->pte_send->toPlainText();
    QByteArray array;

    //Hex复选框
    if(ui->chk_send_hex->checkState() == Qt::Checked){
        array = QString2Hex(data);  //HEX 16进制
    }else{
        array = data.toLatin1();    //ASCII
    }
    global_port.write(array);   //发送数据
}

//接收数据槽函数
void Serial::receive_data(void)
{
    QByteArray array = global_port.readAll();
    QString str_rev;

    if(ui->chk_rev_hex->checkState() == Qt::Checked){   //HEX 16进制
        if(ui->chk_rev_line->checkState() == Qt::Checked){  //自动换行
            if(ui->chk_rev_time->checkState() == Qt::Checked){  //显示时间
                //获取当前系统时间
                QDateTime nowtime = QDateTime::currentDateTime();
                //时间转换为字符串格式
                str_rev = "[" + nowtime.toString("yyyy-MM-dd hh:mm:ss") + "] ";
                //加上接收数据 转换为16进制并空格分开 接收数据换行
                str_rev += QString(array.toHex(' ').toUpper().append(' ')).append("\r\n");
            }else{
                str_rev = QString(array.toHex(' ').toUpper().append(' ')).append("\r\n");
            }
        }else{
            str_rev = QString(array.toHex(' ').toUpper().append(' '));
        }

    }else{
        if(ui->chk_rev_line->checkState() == Qt::Checked){
            if(ui->chk_rev_time->checkState() == Qt::Checked){
                QDateTime nowtime = QDateTime::currentDateTime();
                str_rev = "[" + nowtime.toString("yyyy-MM-dd hh:mm:ss") + "] ";
                str_rev += QString(array).append("\r\n");
            }else{
                str_rev = QString(array).append("\r\n");
            }
        }else{
            str_rev = QString(array);
        }

    }

    //将光标定位到最后
    ui->tb_rev->moveCursor(QTextCursor::End);
    //文本框显示接收数据
    ui->tb_rev->insertPlainText(str_rev);

}

//清空接收文本框槽函数
void Serial::btn_clear_rev(bool)
{
    ui->tb_rev->clear();
}

//自动触发复选框  启动定时器和停止定时器
void Serial::on_checkBox_stateChanged(int arg1)
{
    if(arg1){
        timer->start(ui->spinBox->value()); //启动定时器
    }else{
        timer->stop();  //停止定时器
    }
}

//打开发送文件槽函数
void Serial::btn_open_send_file(bool)
{
    QString path = QFileDialog::getOpenFileName(this,"open","../","TXT(*.txt)");
    if(!path.isEmpty()){
        QFile file(path);
        bool isOk = file.open(QIODevice::ReadOnly);
        if(isOk){
            ui->pte_send->setPlainText(QString(file.readAll()));
        }
        file.close();
    }
}

//保存接收日志槽函数
void Serial::btn_save_rev_log(bool)
{
    QString path = QFileDialog::getSaveFileName(this,"save","../","TXT(*.txt)");
    if(!path.isEmpty()){
        QFile file(path);
        bool isOk = file.open(QIODevice::WriteOnly);
        if(isOk){
            file.write(ui->tb_rev->toPlainText().toStdString().data());
        }
        file.close();
    }
}
