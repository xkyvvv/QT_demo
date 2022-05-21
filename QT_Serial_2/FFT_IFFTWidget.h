#ifndef FFT_IFFTWIDGET_H
#define FFT_IFFTWIDGET_H

#include <QtWidgets\QtWidgets> //包含QtWidgets头文件
#include "myChartView.h"
#include <QtCharts\QtCharts>
#include "FFT.h"
#include "serial.h"

#define MAXFFTLENGTH 1024

class FFT_IFFTWidget:public QWidget
{
    Q_OBJECT
public:
    FFT_IFFTWidget(QWidget *parent = 0); //构造函数，参数是父窗体指针，默认是0，即没有父窗口
    void loadDataPushButtonClicked();   //加载数据
    void saveDataPushButtonClicked();   //保存数据
    void FFTCheckBoxChanged();        //FFT
    void IFFTCheckBoxChanged();     //IFFT
    void clearWavePushButtonCilcked(); //清除波形
    void saveWavePushButtonClicked(); //保存波形
private:
    /********************************FFT/IFFT***********************************/
    QLineSeries *FFTLineSeries = new QLineSeries();//创建折线序列
    QChart *FFTChart = new QChart();//创建图表chart
     ChartView *FFTchartView = new ChartView(FFTChart);
    QScatterSeries *FFTScatterSeries = new QScatterSeries(); //创建散点序列

    double vecRl[MAXFFTLENGTH];        //数据源实部
    double vecIm[MAXFFTLENGTH];  //虚部
    double res[MAXFFTLENGTH];  //模
    Complex* inVec = new Complex[MAXFFTLENGTH];
    Complex* outVec = new Complex[MAXFFTLENGTH];
    Complex* invert = new Complex[MAXFFTLENGTH];

    /*************************************************************************/
    QPushButton* loadDataQPushButton = new QPushButton;  //加载数据
    QPushButton* saveDataQPushButton = new QPushButton;  //保存数据
    QCheckBox* FFTCheckBox = new QCheckBox;   //FFT
    QCheckBox* IFFTCheckBox = new QCheckBox;  //IFFT
    QLabel* pointsLabel = new QLabel;  //点数
    QComboBox* pointsComBox = new QComboBox;   //点数  下拉框
    QPushButton* clearWaveQPushButton = new QPushButton;  //清除波形按钮
    QPushButton* saveWaveQPushButton = new QPushButton;  //保存波形按钮
    CFFT* FFT = new CFFT;
    CFFT* IFFT = new CFFT;
    int FFTLength = 256;
    bool transformDirection = true;

};

#endif // FFT_IFFTWIDGET_H
