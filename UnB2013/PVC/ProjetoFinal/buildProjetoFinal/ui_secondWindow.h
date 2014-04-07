/********************************************************************************
** Form generated from reading UI file 'secondWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDWINDOW_H
#define UI_SECONDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_secondWindow
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *window1;
    QLabel *window2;
    QLabel *window3;
    QLabel *window4;
    QLabel *window5;
    QLabel *window6;
    QLabel *window7;
    QLabel *window8;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *shadowValue;
    QSlider *shadowSlider;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLabel *label_5;
    QSlider *horizontalSlider_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QLabel *label_9;
    QSlider *horizontalSlider_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLabel *label_7;
    QSlider *horizontalSlider_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_10;
    QLabel *label_11;
    QSlider *horizontalSlider_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_3;
    QLabel *shadowValue_2;
    QSlider *shadowSlider_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_12;
    QLabel *label_13;
    QSlider *horizontalSlider_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_14;
    QLabel *label_15;
    QSlider *horizontalSlider_7;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_16;
    QLabel *label_17;
    QSlider *horizontalSlider_8;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_18;
    QLabel *label_19;
    QSlider *horizontalSlider_9;

    void setupUi(QWidget *secondWindow)
    {
        if (secondWindow->objectName().isEmpty())
            secondWindow->setObjectName(QStringLiteral("secondWindow"));
        secondWindow->resize(1298, 438);
        label = new QLabel(secondWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 460, 521, 111));
        layoutWidget = new QWidget(secondWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(52, 12, 811, 331));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        window1 = new QLabel(layoutWidget);
        window1->setObjectName(QStringLiteral("window1"));
        window1->setAutoFillBackground(true);

        gridLayout->addWidget(window1, 0, 0, 1, 1);

        window2 = new QLabel(layoutWidget);
        window2->setObjectName(QStringLiteral("window2"));
        window2->setAutoFillBackground(true);

        gridLayout->addWidget(window2, 0, 1, 1, 1);

        window3 = new QLabel(layoutWidget);
        window3->setObjectName(QStringLiteral("window3"));
        window3->setAutoFillBackground(true);

        gridLayout->addWidget(window3, 0, 2, 1, 1);

        window4 = new QLabel(layoutWidget);
        window4->setObjectName(QStringLiteral("window4"));
        window4->setAutoFillBackground(true);

        gridLayout->addWidget(window4, 0, 3, 1, 1);

        window5 = new QLabel(layoutWidget);
        window5->setObjectName(QStringLiteral("window5"));
        window5->setAutoFillBackground(true);

        gridLayout->addWidget(window5, 1, 0, 1, 1);

        window6 = new QLabel(layoutWidget);
        window6->setObjectName(QStringLiteral("window6"));
        window6->setAutoFillBackground(true);

        gridLayout->addWidget(window6, 1, 1, 1, 1);

        window7 = new QLabel(layoutWidget);
        window7->setObjectName(QStringLiteral("window7"));
        window7->setAutoFillBackground(true);

        gridLayout->addWidget(window7, 1, 2, 1, 1);

        window8 = new QLabel(layoutWidget);
        window8->setObjectName(QStringLiteral("window8"));
        window8->setAutoFillBackground(true);

        gridLayout->addWidget(window8, 1, 3, 1, 1);

        widget = new QWidget(secondWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(870, 30, 421, 371));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        shadowValue = new QLabel(widget);
        shadowValue->setObjectName(QStringLiteral("shadowValue"));

        horizontalLayout_3->addWidget(shadowValue);

        shadowSlider = new QSlider(widget);
        shadowSlider->setObjectName(QStringLiteral("shadowSlider"));
        shadowSlider->setMaximum(100);
        shadowSlider->setValue(50);
        shadowSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(shadowSlider);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        horizontalSlider_2 = new QSlider(widget);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setMaximum(100);
        horizontalSlider_2->setValue(50);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(horizontalSlider_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_6->addWidget(label_8);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_6->addWidget(label_9);

        horizontalSlider_4 = new QSlider(widget);
        horizontalSlider_4->setObjectName(QStringLiteral("horizontalSlider_4"));
        horizontalSlider_4->setMaximum(100);
        horizontalSlider_4->setValue(50);
        horizontalSlider_4->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(horizontalSlider_4);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_5->addWidget(label_7);

        horizontalSlider_3 = new QSlider(widget);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setMaximum(100);
        horizontalSlider_3->setValue(50);
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(horizontalSlider_3);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_7->addWidget(label_10);

        label_11 = new QLabel(widget);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_7->addWidget(label_11);

        horizontalSlider_5 = new QSlider(widget);
        horizontalSlider_5->setObjectName(QStringLiteral("horizontalSlider_5"));
        horizontalSlider_5->setMaximum(100);
        horizontalSlider_5->setValue(50);
        horizontalSlider_5->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(horizontalSlider_5);


        verticalLayout_2->addLayout(horizontalLayout_7);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_8->addWidget(label_3);

        shadowValue_2 = new QLabel(widget);
        shadowValue_2->setObjectName(QStringLiteral("shadowValue_2"));

        horizontalLayout_8->addWidget(shadowValue_2);

        shadowSlider_2 = new QSlider(widget);
        shadowSlider_2->setObjectName(QStringLiteral("shadowSlider_2"));
        shadowSlider_2->setMaximum(100);
        shadowSlider_2->setValue(50);
        shadowSlider_2->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(shadowSlider_2);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_12 = new QLabel(widget);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_9->addWidget(label_12);

        label_13 = new QLabel(widget);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_9->addWidget(label_13);

        horizontalSlider_6 = new QSlider(widget);
        horizontalSlider_6->setObjectName(QStringLiteral("horizontalSlider_6"));
        horizontalSlider_6->setMaximum(100);
        horizontalSlider_6->setValue(50);
        horizontalSlider_6->setOrientation(Qt::Horizontal);

        horizontalLayout_9->addWidget(horizontalSlider_6);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_14 = new QLabel(widget);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_10->addWidget(label_14);

        label_15 = new QLabel(widget);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_10->addWidget(label_15);

        horizontalSlider_7 = new QSlider(widget);
        horizontalSlider_7->setObjectName(QStringLiteral("horizontalSlider_7"));
        horizontalSlider_7->setMaximum(100);
        horizontalSlider_7->setValue(50);
        horizontalSlider_7->setOrientation(Qt::Horizontal);

        horizontalLayout_10->addWidget(horizontalSlider_7);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_16 = new QLabel(widget);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_11->addWidget(label_16);

        label_17 = new QLabel(widget);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_11->addWidget(label_17);

        horizontalSlider_8 = new QSlider(widget);
        horizontalSlider_8->setObjectName(QStringLiteral("horizontalSlider_8"));
        horizontalSlider_8->setMaximum(100);
        horizontalSlider_8->setValue(50);
        horizontalSlider_8->setOrientation(Qt::Horizontal);

        horizontalLayout_11->addWidget(horizontalSlider_8);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_18 = new QLabel(widget);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_12->addWidget(label_18);

        label_19 = new QLabel(widget);
        label_19->setObjectName(QStringLiteral("label_19"));

        horizontalLayout_12->addWidget(label_19);

        horizontalSlider_9 = new QSlider(widget);
        horizontalSlider_9->setObjectName(QStringLiteral("horizontalSlider_9"));
        horizontalSlider_9->setMaximum(100);
        horizontalSlider_9->setValue(50);
        horizontalSlider_9->setOrientation(Qt::Horizontal);

        horizontalLayout_12->addWidget(horizontalSlider_9);


        verticalLayout_3->addLayout(horizontalLayout_12);


        horizontalLayout->addLayout(verticalLayout_3);


        retranslateUi(secondWindow);

        QMetaObject::connectSlotsByName(secondWindow);
    } // setupUi

    void retranslateUi(QWidget *secondWindow)
    {
        secondWindow->setWindowTitle(QApplication::translate("secondWindow", "Form", 0));
        label->setText(QApplication::translate("secondWindow", "Janela auxiliar para vizualiza\303\247\303\243o de processos intermedi\303\241rios", 0));
        window1->setText(QString());
        window2->setText(QString());
        window3->setText(QString());
        window4->setText(QString());
        window5->setText(QString());
        window6->setText(QString());
        window7->setText(QString());
        window8->setText(QString());
        label_2->setText(QApplication::translate("secondWindow", "shadow", 0));
        shadowValue->setText(QApplication::translate("secondWindow", "50", 0));
        label_4->setText(QApplication::translate("secondWindow", "highHue[0]", 0));
        label_5->setText(QApplication::translate("secondWindow", "value", 0));
        label_8->setText(QApplication::translate("secondWindow", "highHue[1]", 0));
        label_9->setText(QApplication::translate("secondWindow", "value", 0));
        label_6->setText(QApplication::translate("secondWindow", "highHue[2]", 0));
        label_7->setText(QApplication::translate("secondWindow", "value", 0));
        label_10->setText(QApplication::translate("secondWindow", "lowHue[0]", 0));
        label_11->setText(QApplication::translate("secondWindow", "value", 0));
        label_3->setText(QApplication::translate("secondWindow", "lowHue[1]", 0));
        shadowValue_2->setText(QApplication::translate("secondWindow", "50", 0));
        label_12->setText(QApplication::translate("secondWindow", "lowHue[2]", 0));
        label_13->setText(QApplication::translate("secondWindow", "value", 0));
        label_14->setText(QApplication::translate("secondWindow", "shadow", 0));
        label_15->setText(QApplication::translate("secondWindow", "value", 0));
        label_16->setText(QApplication::translate("secondWindow", "shadow", 0));
        label_17->setText(QApplication::translate("secondWindow", "value", 0));
        label_18->setText(QApplication::translate("secondWindow", "shadow", 0));
        label_19->setText(QApplication::translate("secondWindow", "value", 0));
    } // retranslateUi

};

namespace Ui {
    class secondWindow: public Ui_secondWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWINDOW_H
