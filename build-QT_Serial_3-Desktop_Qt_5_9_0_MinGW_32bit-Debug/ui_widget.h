/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_state;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *open_serialport;
    QPushButton *close_serialport;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *com;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QTextEdit *textEdit;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *start;
    QPushButton *pause;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_3;
    QLCDNumber *lcdNumber;
    QTableWidget *tableWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_9;
    QCustomPlot *widget;
    QGroupBox *groupBox_3;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_X;
    QCheckBox *checkBox_Y;
    QCheckBox *checkBox_XY;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *clear_table;
    QPushButton *save_table;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1237, 713);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(941, 21, 219, 228));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 43, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_state = new QLabel(groupBox);
        label_state->setObjectName(QStringLiteral("label_state"));

        horizontalLayout_3->addWidget(label_state);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        open_serialport = new QPushButton(groupBox);
        open_serialport->setObjectName(QStringLiteral("open_serialport"));

        horizontalLayout_2->addWidget(open_serialport);

        close_serialport = new QPushButton(groupBox);
        close_serialport->setObjectName(QStringLiteral("close_serialport"));

        horizontalLayout_2->addWidget(close_serialport);


        gridLayout->addLayout(horizontalLayout_2, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        com = new QComboBox(groupBox);
        com->setObjectName(QStringLiteral("com"));

        horizontalLayout->addWidget(com);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(941, 274, 280, 321));
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        textEdit = new QTextEdit(groupBox_2);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        horizontalLayout_4->addWidget(textEdit);

        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 620, 295, 30));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        start = new QPushButton(layoutWidget);
        start->setObjectName(QStringLiteral("start"));

        horizontalLayout_7->addWidget(start);

        pause = new QPushButton(layoutWidget);
        pause->setObjectName(QStringLiteral("pause"));

        horizontalLayout_7->addWidget(pause);

        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(320, 620, 201, 31));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_8->addWidget(label_3);

        lcdNumber = new QLCDNumber(layoutWidget1);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        horizontalLayout_8->addWidget(lcdNumber);

        tableWidget = new QTableWidget(Widget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(680, 30, 241, 561));
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 20, 651, 571));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout_9 = new QHBoxLayout(tab);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        widget = new QCustomPlot(tab);
        widget->setObjectName(QStringLiteral("widget"));

        horizontalLayout_9->addWidget(widget);

        tabWidget->addTab(tab, QString());
        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(1090, 600, 121, 101));
        widget1 = new QWidget(groupBox_3);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 20, 45, 73));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        checkBox_X = new QCheckBox(widget1);
        checkBox_X->setObjectName(QStringLiteral("checkBox_X"));
        checkBox_X->setChecked(true);

        verticalLayout->addWidget(checkBox_X);

        checkBox_Y = new QCheckBox(widget1);
        checkBox_Y->setObjectName(QStringLiteral("checkBox_Y"));

        verticalLayout->addWidget(checkBox_Y);

        checkBox_XY = new QCheckBox(widget1);
        checkBox_XY->setObjectName(QStringLiteral("checkBox_XY"));

        verticalLayout->addWidget(checkBox_XY);

        widget2 = new QWidget(Widget);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(700, 630, 195, 30));
        horizontalLayout_5 = new QHBoxLayout(widget2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        clear_table = new QPushButton(widget2);
        clear_table->setObjectName(QStringLiteral("clear_table"));

        horizontalLayout_5->addWidget(clear_table);

        save_table = new QPushButton(widget2);
        save_table->setObjectName(QStringLiteral("save_table"));

        horizontalLayout_5->addWidget(save_table);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Widget", "\344\270\262\345\217\243\350\256\276\347\275\256", Q_NULLPTR));
        label_state->setText(QApplication::translate("Widget", "\344\270\262\345\217\243\346\234\252\346\211\223\345\274\200", Q_NULLPTR));
        open_serialport->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        close_serialport->setText(QApplication::translate("Widget", "\345\205\263\351\227\255\344\270\262\345\217\243", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\344\270\262\345\217\243\345\217\267:", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Widget", "\346\223\215\344\275\234\350\256\260\345\275\225", Q_NULLPTR));
        start->setText(QApplication::translate("Widget", "\345\274\200\345\247\213", Q_NULLPTR));
        pause->setText(QApplication::translate("Widget", "\346\232\202\345\201\234", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "\345\275\223\345\211\215\346\270\251\345\272\246\357\274\232", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "\345\256\236\346\227\266\346\270\251\345\272\246", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("Widget", "\350\275\264\347\274\251\346\224\276", Q_NULLPTR));
        checkBox_X->setText(QApplication::translate("Widget", "X", Q_NULLPTR));
        checkBox_Y->setText(QApplication::translate("Widget", "Y", Q_NULLPTR));
        checkBox_XY->setText(QApplication::translate("Widget", "XY", Q_NULLPTR));
        clear_table->setText(QApplication::translate("Widget", "\346\270\205\347\251\272\350\241\250", Q_NULLPTR));
        save_table->setText(QApplication::translate("Widget", "\344\277\235\345\255\230\350\241\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
