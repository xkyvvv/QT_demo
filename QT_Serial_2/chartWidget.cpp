#include "chartWidget.h"

#define X_WIDTH 99
#define BUFSIZE 1024


chartWidget::chartWidget(QWidget *parent,Serial *m_serial_t):QWidget(parent)
{
    QHBoxLayout *hLayoutDisp = new QHBoxLayout;
    QVBoxLayout *vLayoutLeft = new QVBoxLayout;
    QVBoxLayout *vLayoutRight = new QVBoxLayout;

    this->setLayout(hLayoutDisp);
    hLayoutDisp->addLayout(vLayoutLeft);
    hLayoutDisp->addLayout(vLayoutRight);

     m_serial = m_serial_t;
    chart->createDefaultAxes();
    //chart->legend()->hide();
    lineSeries->setPen(QPen(Qt::darkRed,3,Qt::SolidLine)); //设置折线画笔宽度，颜色和线型
    lineSeries->setUseOpenGL(true);   //绘图加速
    chart->addSeries(lineSeries);//将折线序列添加到图表

    scatterSeries->setPen(QPen(Qt::darkRed,3,Qt::SolidLine)); //设置画笔
    scatterSeries->setColor(QColor(255,128,0));  //设置颜色
    scatterSeries->setMarkerShape(QScatterSeries::MarkerShapeCircle);//散点形状
    //scatterSeries->setName("Scatter Series");//设置散点序列图例
    scatterSeries->setUseOpenGL(true);   //绘图加速
    chart->addSeries(scatterSeries);//将散点序列添加到图表

    chart->createDefaultAxes();//设置默认的坐标系，不设置将不显示坐标轴

    QPen gridLinePen(QColor::fromRgb(192,192,192));//设置网格线画笔
    gridLinePen.setWidth(1);//设置线宽是1
    gridLinePen.setStyle(Qt::DashLine); //设置画笔样式

    QValueAxis *axisX = (QValueAxis*)chart->axes(Qt::Horizontal).first();//获得图表的X轴指针
    //axisX->setTitleText("Wavelength (nm)");//设置X轴标题
    //axisX->setLabelsFont(QFont("Arial",12));//设置标签字体
    //axisX->setTitleFont(QFont("Arial",12,QFont::Bold));//设置X轴标题字体
    axisX->setRange(0,X_WIDTH);//设置X轴范围
    axisX->setGridLinePen(gridLinePen);//设置网格线画笔

    QValueAxis *axisY = (QValueAxis*)chart->axes(Qt::Vertical).first();//获得图表的Y轴指针
    //axisY->setTitleText("Intensity (arb unit)");//设置Y轴标题
    //axisY->setLabelsFont(QFont("Arial",12));//设置标签字体
    //axisY->setTitleFont(QFont("Arial",12,QFont::Bold));//设置Y轴标题字体
    axisY->setRange(-1.1,1.1);//设置Y轴范围
    axisY->setGridLinePen(gridLinePen);//设置网格线画笔

    //chartView->setRubberBand(QChartView::RectangleRubberBand);   //设置波形可以缩放
    chartView->setRenderHint(QPainter::Antialiasing);   //抗锯齿
    chartView->setChart(chart);//设置图表视图窗口要显示的图表
    vLayoutRight->addWidget(chartView);

    receiveTextEdit->setFixedHeight(100);
    receiveTextEdit->setReadOnly(true);//多行文本框设置只读状态
    receiveTextEdit->setPlaceholderText("数据接收区显示");//输入框提示信息
    vLayoutRight->addWidget(receiveTextEdit);

     vLayoutLeft->setAlignment(Qt::AlignTop);
     waveSettingGroupBox->setTitle("波形");
     waveSettingGroupBox->setFixedHeight(240);
     vLayoutLeft->addWidget(waveSettingGroupBox);
     recSettingGroupBox->setTitle("数据");
     recSettingGroupBox->setFixedHeight(120);
     vLayoutLeft->addWidget(recSettingGroupBox);
     QGridLayout *gridLayoutDispGroupBox = new QGridLayout;
     waveSettingGroupBox->setLayout(gridLayoutDispGroupBox);

     chartModeComBox->addItems({"线","点","点和线"});
     connect(chartModeComBox, &QComboBox::currentTextChanged, this, &chartModeQComBoxChanged);
     gridLayoutDispGroupBox->addWidget(chartModeComBox,0,1);
     chartModeLabel->setText("绘图模式");
     gridLayoutDispGroupBox->addWidget(chartModeLabel,0,0);
     openFilePushButton->setText("打开文件");
     connect(openFilePushButton,&QPushButton::clicked,this,&openFileQPushButtonClicked);
     gridLayoutDispGroupBox->addWidget(openFilePushButton,3,0);
     saveWavePushButton->setText("保存波形");
     connect(saveWavePushButton,&QPushButton::clicked,this,&saveWaveQPushButtonClicked);
     clearWavePushButton->setText("清除波形");
     connect(clearWavePushButton,&QPushButton::clicked,this,&clearWaveQPushButtonClicked);
     stopDisplayQCheckBox->setText("停止显示");
     connect(stopDisplayQCheckBox,&QCheckBox::stateChanged,this,&stopDisplayQCheckBoxChanged);
     gridLayoutDispGroupBox->addWidget(stopDisplayQCheckBox,2,0);
     gridLayoutDispGroupBox->addWidget(clearWavePushButton,2,1);
     gridLayoutDispGroupBox->addWidget(saveWavePushButton,3,1);
     QGridLayout *gridLayoutDataDispGroupBox = new QGridLayout;
     recSettingGroupBox->setLayout(gridLayoutDataDispGroupBox);
     hexDisplayCheckBox->setText("HEX");
     connect(hexDisplayCheckBox, &QCheckBox::stateChanged, this, &hexDisplayQCheckBoxChanged);//按钮点击事件处理连接
     gridLayoutDataDispGroupBox->addWidget(hexDisplayCheckBox,0,0);
     asciiDisplayCheckBox->setText("ASCII");
     asciiDisplayCheckBox->setCheckState(Qt::Checked);
     connect(asciiDisplayCheckBox, &QCheckBox::stateChanged, this, &asciiDisplayQCheckBoxChanged);//按钮点击事件处理连接
     gridLayoutDataDispGroupBox->addWidget(asciiDisplayCheckBox,0,1);
     saveFilePushButton->setText("保存数据");
     connect(saveFilePushButton,&QPushButton::clicked,this,&saveFileQPushButtonClicked);
     gridLayoutDataDispGroupBox->addWidget(saveFilePushButton,1,0);
     clearDataPushButton->setText("清除数据");
     connect(clearDataPushButton,&QPushButton::clicked,this,&clearDataQPushButtonClicked);
     gridLayoutDataDispGroupBox->addWidget(clearDataPushButton,1,1);

     connect(m_serial, SIGNAL(readSignal()), this, SLOT(readSerialData()));
}


// 读取从自定义串口类获得的数据
void chartWidget::readSerialData()
{
    if(!stopDisplay)
    {
        if(ASCIIDisp)receiveTextEdit->insertPlainText(m_serial->hexStringToByteArray(m_serial->getReadBuf().toHex(' '))); //ascii显示
        else receiveTextEdit->insertPlainText(m_serial->getReadBuf().toHex(' '));   //hex显示
    }
    if(bufIndex==BUFSIZE-1)   //判断缓冲区是否已满
    {
        for(int j=0;j<BUFSIZE-1;j++)
            buf[j] = buf[j+1];          //丢弃第一个数据
        buf[BUFSIZE-1] = m_serial->getReadBuf().toFloat();  //最新数据放在最后 ，丢弃第一个数，先进先出
    }
   else
    {
        buf[bufIndex++] = m_serial->getReadBuf().toFloat();
    }

   if(!stopDisplay)
    {
        data.clear();//清除data中包含的QPointF数据
        lineSeries->clear();//清除所有图表数据
        scatterSeries->clear();
        for (int j=0; j<bufIndex; j++)
        {
            //往data中添加数据，offset每次不同，所以每次数据也不同。
            data.append(QPointF(j, buf[j]));
        }
        if(chartMode == 0)
            lineSeries->append(data);//向折线序列添加数据列表data
        else if(chartMode == 1)
            scatterSeries->append(data);
        else
        {
            lineSeries->append(data);//向折线序列添加数据列表data
            scatterSeries->append(data);
        }
    }
    m_serial->clearReadBuf(); // 读取完后，清空数据缓冲区
}

//绘图模式
void chartWidget::chartModeQComBoxChanged()
{
    QString str=chartModeComBox->currentText();//获取当前的显示文本，返回一个QString对象。
    if(str == tr("线"))
        chartMode = 0;
    else if(str == tr("点"))
        chartMode = 1;
    else if(str == tr("点和线"))
        chartMode = 2;
    else
        chartMode = 0;
}

//保存波形
void chartWidget::saveWaveQPushButtonClicked()
{
    QString imagFile = QFileDialog::getSaveFileName(this,tr("Save png"),"",tr("*.png")); //选择路径</font><br />
    QImage image(imagFile);
    QPixmap p = chartView->grab();
    image = p.toImage();
    image.save(imagFile);
}
//打开文件
void chartWidget::openFileQPushButtonClicked()
{
    data.clear();//清除data中包含的QPointF数据
    lineSeries->clear();//清除所有图表数据
    scatterSeries->clear();
    QString f = QFileDialog::getOpenFileName(this, QString("选择文件"), QString("/"),QString("TEXT(*.txt)"));
    QFile file(f);
    float array[50];
    if(! file.open(QIODevice::ReadOnly|QIODevice::Text))
        qDebug()<<file.errorString();
    else
        qDebug()<<"openok";
      file.seek(0);

      QTextStream shuru(&file);
      int a=0;
      while(! shuru.atEnd())
      {
          QString line=shuru.readLine();    //按行读取数据
          QStringList strList = line.split(",");    //按照逗号分割数据
          for (int i = 0; i < strList.count(); i++)
          {
              array[i] = strList.at(i).toFloat();   //数据类型转换
          }
          for(int i=0;i < strList.count()-1;i++,a++)
            data.append(QPointF(a,array[i]));     //添加数据
          receiveTextEdit->insertPlainText(line);

          //qDebug()<<array;
          receiveTextEdit->insertPlainText("\n");
          //qDebug()<<line;
      }

      file.close();
      if(chartMode == 0)
          lineSeries->append(data);//向折线序列添加数据列表data
      else if(chartMode == 1)
          scatterSeries->append(data);
      else
      {
          lineSeries->append(data);//向折线序列添加数据列表data
          scatterSeries->append(data);
      }
}
//   16 32 64 128 256 512 1024

//清除数据
void chartWidget::clearDataQPushButtonClicked()
{
    receiveTextEdit->clear();
}
//保存文件
void chartWidget::saveFileQPushButtonClicked()
{
    QString textFile = QFileDialog::getSaveFileName(this,tr("Save txt"),"",tr("text (*.txt)")); //选择路径</font><br />
    QFile file(textFile);//文件命名
    if (!file.open(QFile::WriteOnly | QFile::Text))     //检测文件是否打开
    {
          QMessageBox::information(this, "Error Message", "Please Select a Text File!");
          return;
    }
    QTextStream out(&file);                 //分行写入文件
    out << receiveTextEdit->toPlainText();
}
//清除波形
void chartWidget::clearWaveQPushButtonClicked()
{
    lineSeries->clear();//清除所有图表数据
    scatterSeries->clear();
    bufIndex = 0;   //数据指针归0
}

//停止显示
void chartWidget::stopDisplayQCheckBoxChanged()
{
    if(stopDisplayQCheckBox->isChecked())  stopDisplay = true;
    else stopDisplay = false;
}

//hex
void chartWidget::hexDisplayQCheckBoxChanged()
{
    if(hexDisplayCheckBox->isChecked())
    {
        ASCIIDisp = false;
        asciiDisplayCheckBox->setCheckState(Qt::Unchecked);
    }
    else
    {
        ASCIIDisp = true;
        asciiDisplayCheckBox->setCheckState(Qt::Checked);
    }
}
//ascii
void chartWidget::asciiDisplayQCheckBoxChanged()
{
    if(asciiDisplayCheckBox->isChecked())
    {
        ASCIIDisp = true;
        hexDisplayCheckBox->setCheckState(Qt::Unchecked);
    }
    else
    {
        ASCIIDisp = false;
        hexDisplayCheckBox->setCheckState(Qt::Checked);
    }
}

