#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyMainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
