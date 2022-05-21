#include "FFT_IFFTWidget.h"

FFT_IFFTWidget::FFT_IFFTWidget(QWidget *parent):QWidget(parent)
{
    /********************************FFT/IFFT***********************************/
     QHBoxLayout *FFTHLayout = new QHBoxLayout;
     QVBoxLayout *FFTVLayout = new QVBoxLayout;
     QVBoxLayout *FFTVLayout2 = new QVBoxLayout;
     QGridLayout *gridLayoutFFT = new QGridLayout;
     this->setLayout(FFTHLayout);
     FFTHLayout->addLayout(FFTVLayout);
     FFTHLayout->addLayout(FFTVLayout2);

     FFTVLayout->addLayout(gridLayoutFFT);

     FFTChart->createDefaultAxes();
     //chart->legend()->hide();
     FFTLineSeries->setPen(QPen(Qt::darkRed,3,Qt::SolidLine)); //设置折线画笔宽度，颜色和线型
     for (int i=0; i<=720; i++)
     {
          //   *FFTLineSeries<<QPointF(i,qSin(qSin(i/180.0*3.14159)));//和append同样功能。
     }
     FFTLineSeries->setUseOpenGL(true);   //绘图加速
     FFTChart->addSeries(FFTLineSeries);//将折线序列添加到图表

     FFTScatterSeries->setPen(QPen(Qt::darkRed,3,Qt::SolidLine)); //设置画笔
    FFTScatterSeries->setColor(QColor(255,128,0));  //设置颜色
    FFTScatterSeries->setMarkerShape(QScatterSeries::MarkerShapeCircle);//散点形状
    //FFTScatterSeries->setName("Scatter Series");//设置散点序列图例
    FFTScatterSeries->setUseOpenGL(true);   //绘图加速
     FFTChart->addSeries(FFTScatterSeries);//将散点序列添加到图表

     FFTChart->createDefaultAxes();//设置默认的坐标系，不设置将不显示坐标轴

     QPen gridLinePen(QColor::fromRgb(192,192,192));//设置网格线画笔
     gridLinePen.setWidth(1);//设置线宽是1
     gridLinePen.setStyle(Qt::DashLine); //设置画笔样式

     QValueAxis *FFTaxisX = (QValueAxis*)FFTChart->axes(Qt::Horizontal).first();//获得图表的X轴指针
     //FFTaxisX->setTitleText("Wavelength (nm)");//设置X轴标题
     //FFTaxisX->setLabelsFont(QFont("Arial",12));//设置标签字体
     //FFTaxisX->setTitleFont(QFont("Arial",12,QFont::Bold));//设置X轴标题字体
     FFTaxisX->setRange(0,FFTLength);//设置X轴范围
     FFTaxisX->setGridLinePen(gridLinePen);//设置网格线画笔

     QValueAxis *FFTaxisY = (QValueAxis*)FFTChart->axes(Qt::Vertical).first();//获得图表的Y轴指针
     //FFTaxisY->setTitleText("Intensity (arb unit)");//设置Y轴标题
     //FFTaxisY->setLabelsFont(QFont("Arial",12));//设置标签字体
     //FFTaxisY->setTitleFont(QFont("Arial",12,QFont::Bold));//设置Y轴标题字体
     FFTaxisY->setRange(0,10);//设置Y轴范围
     FFTaxisY->setGridLinePen(gridLinePen);//设置网格线画笔

     FFTchartView->setRenderHint(QPainter::Antialiasing);   //抗锯齿
     FFTchartView->setChart(FFTChart);//设置图表视图窗口要显示的图表
     FFTVLayout2->addWidget(FFTchartView);

     gridLayoutFFT->setSpacing(20);
     gridLayoutFFT->setMargin(2);
     FFTVLayout->setAlignment(Qt::AlignTop);
     loadDataQPushButton->setText("加载数据");
     connect(loadDataQPushButton,&QPushButton::clicked,this,&loadDataPushButtonClicked);
     gridLayoutFFT->addWidget(loadDataQPushButton,0,0);
     saveDataQPushButton->setText("保存数据");
     connect(saveDataQPushButton,&QPushButton::clicked,this,&saveDataPushButtonClicked);
     gridLayoutFFT->addWidget(saveDataQPushButton,0,1);
     FFTCheckBox->setText("FFT");
     FFTCheckBox->setCheckState(Qt::Checked);
     connect(FFTCheckBox, &QCheckBox::stateChanged, this, &FFTCheckBoxChanged);
     gridLayoutFFT->addWidget(FFTCheckBox,1,0);
     IFFTCheckBox->setText("IFFT");
     connect(IFFTCheckBox,&QPushButton::clicked,this,&IFFTCheckBoxChanged);
     gridLayoutFFT->addWidget(IFFTCheckBox,1,1);
     pointsLabel->setText("点数");
     gridLayoutFFT->addWidget(pointsLabel,2,0);
     pointsComBox->addItems({"16","32","64","128","256","512","1024"});
     pointsComBox->setCurrentIndex(4);   //设置默认值
     gridLayoutFFT->addWidget(pointsComBox,2,1);
     clearWaveQPushButton->setText("清除波形");
     connect(clearWaveQPushButton,&QPushButton::clicked,this,&clearWavePushButtonCilcked);
     gridLayoutFFT->addWidget(clearWaveQPushButton,3,0);
     saveWaveQPushButton->setText("保存波形");
     connect(saveWaveQPushButton,&QPushButton::clicked,this,&saveWavePushButtonClicked);
     gridLayoutFFT->addWidget(saveWaveQPushButton,3,1);
}

void FFT_IFFTWidget::loadDataPushButtonClicked()
{
    FFTLength = pointsComBox->currentText().toInt();
    QString f = QFileDialog::getOpenFileName(this, QString("选择文件"), QString("/"),QString("TEXT(*.txt)"));
    QFile file(f);
    if(! file.open(QIODevice::ReadOnly|QIODevice::Text))
        qDebug()<<file.errorString();
    else
         qDebug()<<"openok";
    file.seek(0);
    QTextStream shuru(&file);
    int index = 0;
    while(! shuru.atEnd())
    {
        QString line=shuru.readLine();    //按行读取数据
        QStringList strList = line.split(",");    //按照逗号分割数据
        for (int i = 0; i < strList.count()-1; i++)
        {
            //array[i] = strList.at(i).toFloat();   //数据类型转换
            if(transformDirection)
            {
                vecRl[index++] = strList.at(i).toFloat();   //数据类型转换
            }
            else
            {
                if(index<FFTLength)
                    vecRl[index++] = strList.at(i).toFloat();   //数据类型转换
                else
                    vecIm[index++%FFTLength] = strList.at(i).toFloat();
            }

        }
    }

    memset(inVec, 0, FFTLength * sizeof(Complex));//初始化全为0
    if(transformDirection)
    {
        for (int i = 0; i < FFTLength; i++)
        {
             inVec[i].rl = vecRl[i];
             inVec[i].im = 0;   //虚部为0
          }
    }
    else
    {
        for (int i = 0; i < FFTLength; i++)   inVec[i].rl = vecRl[i];
        for (int i = 0; i < FFTLength; i++)   inVec[i].im = vecIm[i];
    }

    QValueAxis *FFTaxisX = (QValueAxis*)FFTChart->axes(Qt::Horizontal).first();//获得图表的X轴指针
    FFTaxisX->setTitleText("Wavelength (nm)");//设置X轴标题
    FFTaxisX->setLabelsFont(QFont("Arial",12));//设置标签字体
    FFTaxisX->setTitleFont(QFont("Arial",12,QFont::Bold));//设置X轴标题字体
    FFTaxisX->setRange(0,FFTLength);//设置X轴范围
   //FFTaxisX->setGridLinePen(gridLinePen);//设置网格线画笔

    if(transformDirection)
    {
        FFT->fft(inVec, FFTLength, outVec);
        for (int i = 0; i < FFTLength; i++)
            res[i] = sqrt((outVec + i)->im * (outVec + i)->im + (outVec + i)->rl * (outVec + i)->rl);
        for(int i=0;i<FFTLength;i++)
             *FFTLineSeries<<QPointF(i,res[i]*2/FFTLength);
    }
    else
    {
        IFFT->ifft(inVec, FFTLength, outVec);
        for(int i=0;i<FFTLength;i++)
             *FFTLineSeries<<QPointF(i,(outVec+i)->rl);
    }

}

void FFT_IFFTWidget::saveDataPushButtonClicked()
{
    QString textFile = QFileDialog::getSaveFileName(this,tr("Save txt"),"",tr("text (*.txt)")); //选择路径
    QFile file(textFile);//文件命名
    if (!file.open(QFile::WriteOnly | QFile::Text))     //检测文件是否打开
    {
          QMessageBox::information(this, "Error Message", "Please Select a Text File!");
          return;
    }
    QTextStream out(&file);                 //分行写入文件
    if(transformDirection)  //FFT
    {
        out <<"/**********************";
        out <<QString::fromLocal8Bit("实部");
        out <<"**********************/";
        out <<"\n";
        for(int i=0;i<FFTLength;i++)
        {
            out << (outVec+i)->rl<<",";
            if((i+1)%10==0) out << "\n";
        }
        out << "\n";
        out <<"/**********************";
        out <<QString::fromLocal8Bit("虚部");
        out <<"**********************/";
        out <<"\n";
        for(int i=0;i<FFTLength;i++)
        {
            out << (outVec+i)->im<<",";
            if((i+1)%10==0) out << "\n";
        }
        out << "\n";
        out <<"/**********************";
        out <<QString::fromLocal8Bit("取模");
        out <<"**********************/";
        out <<"\n";
        for(int i=0;i<FFTLength;i++)
        {
            out << res[i]<<",";
            if((i+1)%10==0) out << "\n";
        }
    }
    else
    {
        for(int i=0;i<FFTLength;i++)
        {
            out << (outVec+i)->rl<<",";
            if((i+1)%10==0) out << "\n";
        }
    }
}

void FFT_IFFTWidget::FFTCheckBoxChanged()
{
    if(FFTCheckBox->isChecked())
    {
        transformDirection = true;
        IFFTCheckBox->setCheckState(Qt::Unchecked);
    }
    else
    {
        transformDirection = false;
        IFFTCheckBox->setCheckState(Qt::Checked);
    }
}

void FFT_IFFTWidget::IFFTCheckBoxChanged()
{
    if(IFFTCheckBox->isChecked())
    {
        transformDirection = false;
        FFTCheckBox->setCheckState(Qt::Unchecked);
    }
    else
    {
        transformDirection = true;
        FFTCheckBox->setCheckState(Qt::Checked);
    }
}

void FFT_IFFTWidget::clearWavePushButtonCilcked()
{
    FFTLineSeries->clear();//清除所有图表数据
    FFTScatterSeries->clear();
}

void FFT_IFFTWidget::saveWavePushButtonClicked()
{
    QString imagFile = QFileDialog::getSaveFileName(this,tr("Save png"),"",tr("*.png")); //选择路径</font><br />
    QImage image(imagFile);
    QPixmap p = FFTchartView->grab();
    image = p.toImage();
    image.save(imagFile);
}
