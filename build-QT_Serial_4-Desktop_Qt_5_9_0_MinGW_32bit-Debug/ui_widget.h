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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *stopbit;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *com;
    QPushButton *open_port;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *baud;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *jiaoyan;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *bit;
    QPushButton *close_port;
    QLabel *label_6;
    QTextEdit *Receive_text_window;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *clear_button2;
    QPushButton *receive_modl;
    QLabel *label_7;
    QTextEdit *send_text_window;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *send_button;
    QPushButton *clear_button_1;
    QPushButton *send_modl;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(648, 489);
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        stopbit = new QComboBox(Widget);
        stopbit->setObjectName(QStringLiteral("stopbit"));

        horizontalLayout_5->addWidget(stopbit);


        gridLayout->addLayout(horizontalLayout_5, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        com = new QComboBox(Widget);
        com->setObjectName(QStringLiteral("com"));

        horizontalLayout->addWidget(com);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        open_port = new QPushButton(Widget);
        open_port->setObjectName(QStringLiteral("open_port"));

        gridLayout->addWidget(open_port, 7, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        baud = new QComboBox(Widget);
        baud->setObjectName(QStringLiteral("baud"));

        horizontalLayout_2->addWidget(baud);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        jiaoyan = new QComboBox(Widget);
        jiaoyan->setObjectName(QStringLiteral("jiaoyan"));

        horizontalLayout_4->addWidget(jiaoyan);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        bit = new QComboBox(Widget);
        bit->setObjectName(QStringLiteral("bit"));

        horizontalLayout_3->addWidget(bit);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        close_port = new QPushButton(Widget);
        close_port->setObjectName(QStringLiteral("close_port"));

        gridLayout->addWidget(close_port, 6, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 6, 1);

        label_6 = new QLabel(Widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 0, 1, 1, 1);

        Receive_text_window = new QTextEdit(Widget);
        Receive_text_window->setObjectName(QStringLiteral("Receive_text_window"));

        gridLayout_2->addWidget(Receive_text_window, 1, 1, 1, 2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        clear_button2 = new QPushButton(Widget);
        clear_button2->setObjectName(QStringLiteral("clear_button2"));

        horizontalLayout_7->addWidget(clear_button2);

        receive_modl = new QPushButton(Widget);
        receive_modl->setObjectName(QStringLiteral("receive_modl"));

        horizontalLayout_7->addWidget(receive_modl);


        gridLayout_2->addLayout(horizontalLayout_7, 2, 2, 1, 1);

        label_7 = new QLabel(Widget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 3, 1, 1, 1);

        send_text_window = new QTextEdit(Widget);
        send_text_window->setObjectName(QStringLiteral("send_text_window"));

        gridLayout_2->addWidget(send_text_window, 4, 1, 1, 2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        send_button = new QPushButton(Widget);
        send_button->setObjectName(QStringLiteral("send_button"));

        horizontalLayout_6->addWidget(send_button);

        clear_button_1 = new QPushButton(Widget);
        clear_button_1->setObjectName(QStringLiteral("clear_button_1"));

        horizontalLayout_6->addWidget(clear_button_1);

        send_modl = new QPushButton(Widget);
        send_modl->setObjectName(QStringLiteral("send_modl"));

        horizontalLayout_6->addWidget(send_modl);


        gridLayout_2->addLayout(horizontalLayout_6, 5, 1, 1, 2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label_5->setText(QApplication::translate("Widget", "\345\201\234\346\255\242\344\275\215\357\274\232", Q_NULLPTR));
        stopbit->clear();
        stopbit->insertItems(0, QStringList()
         << QApplication::translate("Widget", "1", Q_NULLPTR)
        );
        label->setText(QApplication::translate("Widget", "\347\253\257\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        open_port->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207\357\274\232", Q_NULLPTR));
        baud->clear();
        baud->insertItems(0, QStringList()
         << QApplication::translate("Widget", "9600", Q_NULLPTR)
         << QApplication::translate("Widget", "300", Q_NULLPTR)
         << QApplication::translate("Widget", "1200", Q_NULLPTR)
         << QApplication::translate("Widget", "2400", Q_NULLPTR)
         << QApplication::translate("Widget", "4800", Q_NULLPTR)
         << QApplication::translate("Widget", "14400", Q_NULLPTR)
         << QApplication::translate("Widget", "19200", Q_NULLPTR)
         << QApplication::translate("Widget", "28800", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("Widget", "\346\240\241\351\252\214\344\275\215\357\274\232", Q_NULLPTR));
        jiaoyan->clear();
        jiaoyan->insertItems(0, QStringList()
         << QApplication::translate("Widget", "0", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\344\275\215\357\274\232", Q_NULLPTR));
        bit->clear();
        bit->insertItems(0, QStringList()
         << QApplication::translate("Widget", "8", Q_NULLPTR)
         << QApplication::translate("Widget", "5", Q_NULLPTR)
         << QApplication::translate("Widget", "6", Q_NULLPTR)
         << QApplication::translate("Widget", "7", Q_NULLPTR)
        );
        close_port->setText(QApplication::translate("Widget", "\345\205\263\351\227\255\344\270\262\345\217\243", Q_NULLPTR));
        label_6->setText(QApplication::translate("Widget", "\346\216\245\346\224\266\347\252\227\345\217\243", Q_NULLPTR));
        clear_button2->setText(QApplication::translate("Widget", "\346\270\205\347\251\272\346\225\260\346\215\256", Q_NULLPTR));
        receive_modl->setText(QApplication::translate("Widget", "\346\226\207\346\234\254\346\250\241\345\274\217", Q_NULLPTR));
        label_7->setText(QApplication::translate("Widget", "\345\217\221\351\200\201\347\252\227\345\217\243", Q_NULLPTR));
        send_button->setText(QApplication::translate("Widget", "\345\217\221\351\200\201\346\225\260\346\215\256", Q_NULLPTR));
        clear_button_1->setText(QApplication::translate("Widget", "\346\270\205\347\251\272\346\225\260\346\215\256", Q_NULLPTR));
        send_modl->setText(QApplication::translate("Widget", "\346\226\207\346\234\254\346\250\241\345\274\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
