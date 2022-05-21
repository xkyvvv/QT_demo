#include "serialWidget.h"

serialWidget::serialWidget(QWidget *parent,Serial *m_serial_t):QWidget(parent)
{
    //定义布局器
    QHBoxLayout *hLayout = new QHBoxLayout;
    QVBoxLayout *vLayoutLeft = new QVBoxLayout;
    QVBoxLayout *vLayoutRight = new QVBoxLayout;

    this->setLayout(hLayout);   //设置布局器
    hLayout->addLayout(vLayoutLeft);  //添加布局器
    hLayout->addLayout(vLayoutRight);  //添加布局器

    serialSettingQGroupBox->setTitle("串口配置");
    vLayoutLeft->addWidget(serialSettingQGroupBox);
    QGridLayout *GroupBoxGridLayout = new QGridLayout;   //网格布局器
    serialSettingQGroupBox->setLayout(GroupBoxGridLayout);

    //串口配置
    serialQLabel->setText("串口号");
    GroupBoxGridLayout->addWidget(serialQLabel,0,0);
    GroupBoxGridLayout->addWidget(serialQComboBox,0,1);
    baudRateQLabel->setText("波特率");
    GroupBoxGridLayout->addWidget(baudRateQLabel,1,0);
    baudRateQComboBox->addItems({"2400","4800","9600","19200","38400","57600","115200","128000","230400","256000"});
    baudRateQComboBox->setCurrentIndex(6);   //设置默认值
    GroupBoxGridLayout->addWidget(baudRateQComboBox,1,1);
    parityBitQLabel->setText("校验位");
    GroupBoxGridLayout->addWidget(parityBitQLabel,2,0);
    parityBitQComboBox->addItems({"无","奇","偶"});
    parityBitQComboBox->setCurrentIndex(0);   //设置默认值
    GroupBoxGridLayout->addWidget(parityBitQComboBox,2,1);
    dataBitsQLabel->setText("数据位");
    GroupBoxGridLayout->addWidget(dataBitsQLabel,3,0);
    dataBitsQComboBox->addItems({"5","6","7","8"});
    dataBitsQComboBox->setCurrentIndex(3);   //设置默认值
    GroupBoxGridLayout->addWidget(dataBitsQComboBox,3,1);
    stopBitQLabel->setText("停止位");
    GroupBoxGridLayout->addWidget(stopBitQLabel,4,0);
    stopBitQComboBox->addItems({"1","1.5","2"});
    stopBitQComboBox->setCurrentIndex(0);   //设置默认值
    GroupBoxGridLayout->addWidget(stopBitQComboBox,4,1);
    openSerialQButton->setText("打开串口");
    GroupBoxGridLayout->addWidget(openSerialQButton,5,1);
    connect(openSerialQButton, &QPushButton::clicked, this, &openPortQPushButtonClicked);
    //接收区
    receiveSettingQGroupBox->setTitle("接收区");
    vLayoutLeft->addWidget(receiveSettingQGroupBox);
    QGridLayout *GroupBoxGridLayout2 = new QGridLayout;
    receiveSettingQGroupBox->setLayout(GroupBoxGridLayout2);
    GroupBoxGridLayout2->addWidget(hexReceiveQCheckBox,0,0);
    hexReceiveQCheckBox->setText("HEX");
    connect(hexReceiveQCheckBox, &QCheckBox::stateChanged, this, &hexReceiveQCheckBoxChanged);
    GroupBoxGridLayout2->addWidget(asciiReceiveQCheckBox,0,1);
    asciiReceiveQCheckBox->setCheckState(Qt::Checked);  //默认ASCII码显示
    asciiReceiveQCheckBox->setText("ASCII");
    connect(asciiReceiveQCheckBox, &QCheckBox::stateChanged, this, &asciiReceiveQCheckBoxChanged);
    GroupBoxGridLayout2->addWidget(stopDisplayQCheckBox,1,0);
    stopDisplayQCheckBox->setText("停止显示");
    connect(stopDisplayQCheckBox, &QCheckBox::stateChanged, this, &stopDispCheckBoxChanged);
    GroupBoxGridLayout2->addWidget(logModeQCheckBox,1,1);
    logModeQCheckBox->setText("日志模式");
    connect(logModeQCheckBox,&QPushButton::clicked,this,&logModeCheckBoxChanged);
    GroupBoxGridLayout2->addWidget(clearReceiveAeraQPushButton,2,0);
    clearReceiveAeraQPushButton->setText("清空接收区");
    connect(clearReceiveAeraQPushButton,&QPushButton::clicked,this,&clearReceiveAeraQPushButtonClicked);
    GroupBoxGridLayout2->addWidget(saveReceiveAeraQPushButton,2,1);
    saveReceiveAeraQPushButton->setText("保存到文件");
    connect(saveReceiveAeraQPushButton,&QPushButton::clicked,this,&saveReceiveAreaQPushBuutonClicked);
    //发送区
    snedSeetingQGroupBox->setTitle("发送区");
    vLayoutLeft->addWidget(snedSeetingQGroupBox);
    QGridLayout *GroupBoxGridLayout3 = new QGridLayout;
    GroupBoxGridLayout3->addWidget(autoSendQLabel,0,0);
    autoSendQLabel->setText("自动发送周期(ms)");
    snedSeetingQGroupBox->setLayout(GroupBoxGridLayout3);
    GroupBoxGridLayout3->addWidget(autoSendQSpinBox,0,1);
    autoSendQSpinBox->setRange(1,10000);
    autoSendQSpinBox->setValue(1000);   //默认周期为1s
    connect(autoSendQSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &spinBoxValueChanged);
    GroupBoxGridLayout3->addWidget(hexSendQCheckBox,1,0);
    hexSendQCheckBox->setText("HEX");
    connect(hexSendQCheckBox, &QCheckBox::stateChanged, this, &hexSendCheckBoxChanged);
    GroupBoxGridLayout3->addWidget(asciiSendQCheckBox,1,1);
    asciiSendQCheckBox->setCheckState(Qt::Checked);  //默认ASCII码发送
    asciiSendQCheckBox->setText("ASCII");
    connect(asciiSendQCheckBox, &QCheckBox::stateChanged, this, &asciiSendCheckBoxChanged);
    GroupBoxGridLayout3->addWidget(autoSendQCheckBox,2,0);
    autoSendQCheckBox->setText("自动发送");
    connect(autoSendQCheckBox,&QCheckBox::stateChanged,this,&autoSendCheckBoxChanged);
    GroupBoxGridLayout3->addWidget(sendDataQPushButton,2,1);
    sendDataQPushButton->setText("发送");
    connect(sendDataQPushButton,&QPushButton::clicked,this,&sendDataPushButtonClicked);

    receiveTextEdit->setAlignment(Qt::AlignLeft);  //设置对齐方式
    receiveTextEdit->setFixedHeight(440);   //设置固定高度
    receiveTextEdit->setReadOnly(true);//多行文本框设置只读状态
    receiveTextEdit->setPlaceholderText("数据接收区显示");//输入框提示信息
    vLayoutRight->addWidget(receiveTextEdit);

    sendTextEdit->setAlignment(Qt::AlignLeft);   //设置对齐方式
    sendTextEdit->setPlaceholderText("请输入要发送的数据!");//输入框提示信息
    vLayoutRight->addWidget(sendTextEdit);

    // 初始化串口
    m_serial = m_serial_t;
    // 寻找可用串口
    QStringList serialStrList;
    serialStrList = m_serial->scanSerial();
    for (int i=0; i<serialStrList.size(); i++)
    {
        serialQComboBox->addItem(serialStrList[i]); // 在serialQComboBox那添加串口号
    }
    // 默认设置波特率为115200
    baudRateQComboBox->setCurrentIndex(6);
    // 当下位机中有数据发送过来时就会响应这个槽函数
    connect(m_serial, SIGNAL(readSignal()), this, SLOT(readSerialData()));/////////////////////////////////////////////////////////

    // 每100ms更新一次串口
    connect(&timer, &QTimer::timeout, this, &serialPortUpdate); //连接计时器timer的timeout信号和generateNewData函数的连接
    timer.start(500);
}

// 读取从自定义串口类获得的数据
void serialWidget::readSerialData()
{
    if(!stopDisplay)  //停止显示判断
    {
        QDateTime current_date_time = QDateTime::currentDateTime();
        QString current_date = current_date_time.toString("yyyy-MM-dd");
        QString current_time = current_date_time.toString("hh:mm:ss.zzz ");
        if(logMode)   //日志模式判断
        {
            //打印时间戳
            receiveTextEdit ->insertPlainText('['+current_date+"  "+current_time+']');
            receiveTextEdit ->insertPlainText("\n");
            qDebug()<<current_date;
            qDebug()<<current_time;
        }
        if(ASCIIDisp)receiveTextEdit ->insertPlainText(m_serial->hexStringToByteArray(m_serial->getReadBuf().toHex(' '))); //ascii显示
        else receiveTextEdit ->insertPlainText(m_serial->getReadBuf().toHex(' '));   //hex显示
        receiveTextEdit->moveCursor(QTextCursor::End); // 在末尾移动光标一格
    }

      //在另一个槽函数中清除
    //m_serial->clearReadBuf(); // 读取完后，清空数据缓冲区
}

void serialWidget::openPortQPushButtonClicked()
{
    if(openSerialQButton->text() == tr("打开串口"))
    {
        if(m_serial->open(serialQComboBox->currentText(), baudRateQComboBox->currentText().toInt(),  //配置串口并打开判断
                     dataBitsQComboBox->currentText().toInt(),parityBitQComboBox->currentText(),
                          stopBitQComboBox->currentText()))
        {
            // 关闭下拉列表使能
            serialQComboBox->setEnabled(false);
            // 修改按钮名称
            openSerialQButton->setText(tr("关闭串口"));
            timer.stop();    //关闭定时器   打开一个串口后不再更新串口
            qDebug()<<"串口已经打开!";
        }
    }
    else
    {
        // 关闭串口
        m_serial->close();
        // 重新开启下拉列表使能
        serialQComboBox->setEnabled(true);
        // 恢复按钮名称
        openSerialQButton->setText(tr("打开串口"));
        timer.start(500); //开启定时器
        qDebug()<<"串口已经关闭!";
    }
     //qDebug()<<sizeof(QString);
}

//更新串口号  定时器调用
void serialWidget::serialPortUpdate(void)
{
    QStringList serialStrList;
    serialQComboBox->clear();
    serialStrList = m_serial->scanSerial();
    for (int i=0; i<serialStrList.size(); i++)
    {
        serialQComboBox->addItem(serialStrList[i]); // 在comboBox那添加串口号
    }
}

// hex
void serialWidget::hexReceiveQCheckBoxChanged()
{
    if(hexReceiveQCheckBox->isChecked())
    {
        ASCIIDisp = false;
        asciiReceiveQCheckBox->setCheckState(Qt::Unchecked);
    }
    else
    {
        ASCIIDisp = true;
        asciiReceiveQCheckBox->setCheckState(Qt::Checked);
    }
}
//ascii
void serialWidget::asciiReceiveQCheckBoxChanged()
{
    if(asciiReceiveQCheckBox->isChecked())
    {
        ASCIIDisp = true;
        hexReceiveQCheckBox->setCheckState(Qt::Unchecked);
    }
    else
    {
        ASCIIDisp = false;
        hexReceiveQCheckBox->setCheckState(Qt::Checked);
    }
}
//停止显示
void serialWidget::stopDispCheckBoxChanged()
{
    if(stopDisplayQCheckBox->isChecked())  stopDisplay = true;
    else stopDisplay = false;
}
//清除显示
void serialWidget::clearReceiveAeraQPushButtonClicked()
{
    receiveTextEdit->clear();
}

//保存接受区
void serialWidget::saveReceiveAreaQPushBuutonClicked()
{
    QString textFile = QFileDialog::getSaveFileName(this,tr("Save txt"),"",tr("text (*.txt)")); //选择路径</font><br />
    QFile file(textFile);//文件命名
    if (!file.open(QFile::WriteOnly | QFile::Text))     //检测文件是否打开
    {
          //QMessageBox::information(this, "Error Message", "Please Select a Text File!");
          return;
    }
    QTextStream out(&file);                 //分行写入文件
    out << receiveTextEdit->toPlainText();
}

//发送数据
void serialWidget::sendDataPushButtonClicked()
{
     if(openSerialQButton->text() == tr("打开串口"))  //判断串口状态，在串口打开时才发送数据
     {
         autoSendDataTimer.stop();  //关闭自动重发定时器
         disconnect(&autoSendDataTimer,&QTimer::timeout,this,&sendDataPushButtonClicked);  //断开连接
         autoSendQCheckBox->setCheckState(Qt::Unchecked);
         QMessageBox::about(this, "提示", "请先打开串口!");
         return ;  //退出
     }
     QString str = sendTextEdit->toPlainText();   //读取TextEdit中的内容
    //ascii发送,即把文本框中的内容当作字符处理，因此要转换为ascii码
     qDebug()<<"转换前:"<<str;
     QByteArray sendBuf;
     if(ASCIISend)   // ascii发送
     {
         sendBuf = str.toUtf8();   //转换
         qDebug()<<"抓换后:"<<sendBuf;
     }
    else             //hex发送
     {
         sendBuf = m_serial->hexStringToByteArray(str);
         qDebug()<<"抓换后:"<<sendBuf;
     }
     m_serial->sendData(sendBuf);  //发送数据
}

//hex
void serialWidget::hexSendCheckBoxChanged()
{
    if(hexSendQCheckBox->isChecked())
    {
        ASCIISend = false;
        asciiSendQCheckBox->setCheckState(Qt::Unchecked);
    }
    else
    {
        ASCIISend = true;
        asciiSendQCheckBox->setCheckState(Qt::Checked);
    }
}
//ascii
void serialWidget::asciiSendCheckBoxChanged()
{
    if(asciiSendQCheckBox->isChecked())
    {
        ASCIISend = true;
        hexSendQCheckBox->setCheckState(Qt::Unchecked);
    }
    else
    {
        ASCIISend = false;
        hexSendQCheckBox->setCheckState(Qt::Checked);
    }
}
//自动重发
void serialWidget::autoSendCheckBoxChanged()
{
    if(autoSendQCheckBox->isChecked())
    {
        autoSendDataTimer.start(autoSendQSpinBox->value());  //开启自动重发定时器
        connect(&autoSendDataTimer,&QTimer::timeout,this,&sendDataPushButtonClicked);  //在设定间隔内不断发送数据
        qDebug()<<"开始定时器";
    }
    else
    {
        autoSendDataTimer.stop();
        disconnect(&autoSendDataTimer,&QTimer::timeout,this,&sendDataPushButtonClicked);  //断开连接
        qDebug()<<"关闭定时器";
    }
}

//自动重发时间设置
void serialWidget::spinBoxValueChanged()
{
    autoSendDataTimer.stop();
    if(autoSendQCheckBox->isChecked())   //判断是否在自动发送
    {
        autoSendDataTimer.start(autoSendQSpinBox->value());
    }
}

//日志模式
void serialWidget::logModeCheckBoxChanged()
{
    if(logModeQCheckBox->isChecked())   logMode = true;
    else logMode = false;
}


