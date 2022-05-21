QT       += core gui
QT += serialport
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets



CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Complex.cpp \
    FFT.cpp \
    FFT_IFFTWidget.cpp \
    chartWidget.cpp \
    main.cpp \
    mainwindow.cpp \
    myChartView.cpp \
    serial.cpp \
    serialWidget.cpp

HEADERS += \
    Complex.h \
    FFT.h \
    FFT_IFFTWidget.h \
    chartWidget.h \
    mainwindow.h \
    myChartView.h \
    serial.h \
    serialWidget.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
