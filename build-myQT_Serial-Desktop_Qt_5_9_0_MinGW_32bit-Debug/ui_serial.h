/********************************************************************************
** Form generated from reading UI file 'serial.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIAL_H
#define UI_SERIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Serial
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_16;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *tb_rev;
    QHBoxLayout *horizontalLayout_14;
    QPlainTextEdit *pte_send;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_send;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QLabel *lab_status;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QComboBox *cmd_port_name;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QComboBox *cmd_baud_rate;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QComboBox *cmd_data_bits;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QComboBox *cmd_parity;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QComboBox *cmd_stop_bits;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QCheckBox *chk_rev_hex;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_12;
    QCheckBox *chk_rev_line;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_13;
    QCheckBox *chk_rev_time;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_8;
    QCheckBox *chk_send_hex;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_11;
    QSpinBox *spinBox;
    QLabel *label_14;
    QSpacerItem *verticalSpacer;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Serial)
    {
        if (Serial->objectName().isEmpty())
            Serial->setObjectName(QStringLiteral("Serial"));
        Serial->resize(794, 592);
        centralwidget = new QWidget(Serial);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_16 = new QHBoxLayout(centralwidget);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tb_rev = new QTextBrowser(groupBox);
        tb_rev->setObjectName(QStringLiteral("tb_rev"));
        tb_rev->setMouseTracking(true);
        tb_rev->setAcceptDrops(true);
        tb_rev->setLineWrapColumnOrWidth(0);
        tb_rev->setAcceptRichText(true);

        verticalLayout_2->addWidget(tb_rev);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        pte_send = new QPlainTextEdit(groupBox);
        pte_send->setObjectName(QStringLiteral("pte_send"));

        horizontalLayout_14->addWidget(pte_send);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btn_send = new QPushButton(groupBox);
        btn_send->setObjectName(QStringLiteral("btn_send"));

        verticalLayout->addWidget(btn_send);


        horizontalLayout_14->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_14);

        verticalLayout_2->setStretch(0, 3);
        verticalLayout_2->setStretch(1, 1);

        horizontalLayout_16->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_2->addWidget(label_7);

        lab_status = new QLabel(groupBox_2);
        lab_status->setObjectName(QStringLiteral("lab_status"));
        lab_status->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lab_status);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        cmd_port_name = new QComboBox(groupBox_2);
        cmd_port_name->setObjectName(QStringLiteral("cmd_port_name"));

        horizontalLayout_3->addWidget(cmd_port_name);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        cmd_baud_rate = new QComboBox(groupBox_2);
        cmd_baud_rate->setObjectName(QStringLiteral("cmd_baud_rate"));

        horizontalLayout_4->addWidget(cmd_baud_rate);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_5->addWidget(label_3);

        cmd_data_bits = new QComboBox(groupBox_2);
        cmd_data_bits->setObjectName(QStringLiteral("cmd_data_bits"));

        horizontalLayout_5->addWidget(cmd_data_bits);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_6->addWidget(label_4);

        cmd_parity = new QComboBox(groupBox_2);
        cmd_parity->setObjectName(QStringLiteral("cmd_parity"));

        horizontalLayout_6->addWidget(cmd_parity);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_7->addWidget(label_5);

        cmd_stop_bits = new QComboBox(groupBox_2);
        cmd_stop_bits->setObjectName(QStringLiteral("cmd_stop_bits"));

        horizontalLayout_7->addWidget(cmd_stop_bits);


        verticalLayout_3->addLayout(horizontalLayout_7);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_8->addWidget(label_6);

        chk_rev_hex = new QCheckBox(groupBox_2);
        chk_rev_hex->setObjectName(QStringLiteral("chk_rev_hex"));

        horizontalLayout_8->addWidget(chk_rev_hex);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_9->addWidget(label_12);

        chk_rev_line = new QCheckBox(groupBox_2);
        chk_rev_line->setObjectName(QStringLiteral("chk_rev_line"));

        horizontalLayout_9->addWidget(chk_rev_line);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_15->addWidget(label_13);

        chk_rev_time = new QCheckBox(groupBox_2);
        chk_rev_time->setObjectName(QStringLiteral("chk_rev_time"));

        horizontalLayout_15->addWidget(chk_rev_time);


        verticalLayout_3->addLayout(horizontalLayout_15);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_10->addWidget(label_8);

        chk_send_hex = new QCheckBox(groupBox_2);
        chk_send_hex->setObjectName(QStringLiteral("chk_send_hex"));

        horizontalLayout_10->addWidget(chk_send_hex);


        verticalLayout_3->addLayout(horizontalLayout_10);

        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout_3->addWidget(checkBox);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        spinBox = new QSpinBox(groupBox_2);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(99);
        spinBox->setMaximum(99999);
        spinBox->setValue(1000);

        horizontalLayout_11->addWidget(spinBox);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_11->addWidget(label_14);


        verticalLayout_3->addLayout(horizontalLayout_11);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_16->addWidget(groupBox_2);

        Serial->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(Serial);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Serial->setStatusBar(statusBar);
        toolBar = new QToolBar(Serial);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        Serial->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(Serial);

        QMetaObject::connectSlotsByName(Serial);
    } // setupUi

    void retranslateUi(QMainWindow *Serial)
    {
        Serial->setWindowTitle(QApplication::translate("Serial", "Serial", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Serial", "\346\225\260\346\215\256\347\252\227\345\217\243 DataWin", Q_NULLPTR));
        btn_send->setText(QApplication::translate("Serial", "\345\217\221\351\200\201", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Serial", "\344\270\262\345\217\243\350\256\276\347\275\256 Config", Q_NULLPTR));
        label_7->setText(QApplication::translate("Serial", "\347\212\266  \346\200\201", Q_NULLPTR));
        lab_status->setText(QApplication::translate("Serial", "CLOSED", Q_NULLPTR));
        label->setText(QApplication::translate("Serial", "\347\253\257  \345\217\243", Q_NULLPTR));
        cmd_port_name->clear();
        cmd_port_name->insertItems(0, QStringList()
         << QApplication::translate("Serial", "COM1", Q_NULLPTR)
         << QApplication::translate("Serial", "COM2", Q_NULLPTR)
         << QApplication::translate("Serial", "COM3", Q_NULLPTR)
         << QApplication::translate("Serial", "COM4", Q_NULLPTR)
        );
        cmd_port_name->setCurrentText(QApplication::translate("Serial", "COM1", Q_NULLPTR));
        label_2->setText(QApplication::translate("Serial", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        cmd_baud_rate->clear();
        cmd_baud_rate->insertItems(0, QStringList()
         << QApplication::translate("Serial", "115200", Q_NULLPTR)
         << QApplication::translate("Serial", "57600", Q_NULLPTR)
         << QApplication::translate("Serial", "38400", Q_NULLPTR)
         << QApplication::translate("Serial", "19200", Q_NULLPTR)
         << QApplication::translate("Serial", "9600", Q_NULLPTR)
         << QApplication::translate("Serial", "4800", Q_NULLPTR)
         << QApplication::translate("Serial", "2400", Q_NULLPTR)
         << QApplication::translate("Serial", "1200", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("Serial", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
        cmd_data_bits->clear();
        cmd_data_bits->insertItems(0, QStringList()
         << QApplication::translate("Serial", "8", Q_NULLPTR)
         << QApplication::translate("Serial", "7", Q_NULLPTR)
         << QApplication::translate("Serial", "6", Q_NULLPTR)
         << QApplication::translate("Serial", "5", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("Serial", "\346\240\241\351\252\214\344\275\215", Q_NULLPTR));
        cmd_parity->clear();
        cmd_parity->insertItems(0, QStringList()
         << QApplication::translate("Serial", "None", Q_NULLPTR)
         << QApplication::translate("Serial", "Even", Q_NULLPTR)
         << QApplication::translate("Serial", "Odd", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("Serial", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        cmd_stop_bits->clear();
        cmd_stop_bits->insertItems(0, QStringList()
         << QApplication::translate("Serial", "1", Q_NULLPTR)
         << QApplication::translate("Serial", "1.5", Q_NULLPTR)
         << QApplication::translate("Serial", "2", Q_NULLPTR)
        );
        label_6->setText(QApplication::translate("Serial", "\346\216\245\346\224\266\346\240\274\345\274\217", Q_NULLPTR));
        chk_rev_hex->setText(QApplication::translate("Serial", "Hex ", Q_NULLPTR));
        label_12->setText(QApplication::translate("Serial", "\350\207\252\345\212\250\346\215\242\350\241\214", Q_NULLPTR));
        chk_rev_line->setText(QApplication::translate("Serial", "Line", Q_NULLPTR));
        label_13->setText(QApplication::translate("Serial", "\346\230\276\347\244\272\346\227\266\351\227\264", Q_NULLPTR));
        chk_rev_time->setText(QApplication::translate("Serial", "Time", Q_NULLPTR));
        label_8->setText(QApplication::translate("Serial", "\345\217\221\351\200\201\346\240\274\345\274\217", Q_NULLPTR));
        chk_send_hex->setText(QApplication::translate("Serial", "Hex", Q_NULLPTR));
        checkBox->setText(QApplication::translate("Serial", "\350\207\252\345\212\250\345\217\221\351\200\201", Q_NULLPTR));
        label_14->setText(QApplication::translate("Serial", "ms", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("Serial", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Serial: public Ui_Serial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIAL_H
