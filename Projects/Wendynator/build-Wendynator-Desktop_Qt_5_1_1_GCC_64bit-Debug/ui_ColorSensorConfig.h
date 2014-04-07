/********************************************************************************
** Form generated from reading UI file 'ColorSensorConfig.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORSENSORCONFIG_H
#define UI_COLORSENSORCONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ColorSensorConfig
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *ColorMinLabel;
    QComboBox *ColorMinChannelOption;
    QHBoxLayout *horizontalLayout;
    QLabel *ColorMinValue;
    QSlider *ColorMinChannelSlider;
    QHBoxLayout *horizontalLayout_6;
    QLabel *ColorMaxLabel;
    QComboBox *ColorMaxChannelOption;
    QHBoxLayout *horizontalLayout_7;
    QLabel *ColorMaxValue;
    QSlider *ColorMaxChannelSlider;
    QPushButton *okButtom;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *inputImg;
    QLabel *outputImgLabel;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *DefineColorLabel;
    QComboBox *DefinedColorOption;

    void setupUi(QWidget *ColorSensorConfig)
    {
        if (ColorSensorConfig->objectName().isEmpty())
            ColorSensorConfig->setObjectName(QStringLiteral("ColorSensorConfig"));
        ColorSensorConfig->resize(641, 432);
        layoutWidget = new QWidget(ColorSensorConfig);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 290, 411, 58));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        ColorMinLabel = new QLabel(layoutWidget);
        ColorMinLabel->setObjectName(QStringLiteral("ColorMinLabel"));

        horizontalLayout_3->addWidget(ColorMinLabel);

        ColorMinChannelOption = new QComboBox(layoutWidget);
        ColorMinChannelOption->setObjectName(QStringLiteral("ColorMinChannelOption"));

        horizontalLayout_3->addWidget(ColorMinChannelOption);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ColorMinValue = new QLabel(layoutWidget);
        ColorMinValue->setObjectName(QStringLiteral("ColorMinValue"));

        horizontalLayout->addWidget(ColorMinValue);

        ColorMinChannelSlider = new QSlider(layoutWidget);
        ColorMinChannelSlider->setObjectName(QStringLiteral("ColorMinChannelSlider"));
        ColorMinChannelSlider->setMaximum(100);
        ColorMinChannelSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(ColorMinChannelSlider);


        horizontalLayout_3->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        ColorMaxLabel = new QLabel(layoutWidget);
        ColorMaxLabel->setObjectName(QStringLiteral("ColorMaxLabel"));

        horizontalLayout_6->addWidget(ColorMaxLabel);

        ColorMaxChannelOption = new QComboBox(layoutWidget);
        ColorMaxChannelOption->setObjectName(QStringLiteral("ColorMaxChannelOption"));

        horizontalLayout_6->addWidget(ColorMaxChannelOption);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        ColorMaxValue = new QLabel(layoutWidget);
        ColorMaxValue->setObjectName(QStringLiteral("ColorMaxValue"));

        horizontalLayout_7->addWidget(ColorMaxValue);

        ColorMaxChannelSlider = new QSlider(layoutWidget);
        ColorMaxChannelSlider->setObjectName(QStringLiteral("ColorMaxChannelSlider"));
        ColorMaxChannelSlider->setMaximum(100);
        ColorMaxChannelSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(ColorMaxChannelSlider);


        horizontalLayout_6->addLayout(horizontalLayout_7);


        verticalLayout->addLayout(horizontalLayout_6);

        okButtom = new QPushButton(ColorSensorConfig);
        okButtom->setObjectName(QStringLiteral("okButtom"));
        okButtom->setGeometry(QRect(450, 290, 80, 61));
        label_3 = new QLabel(ColorSensorConfig);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 260, 52, 14));
        label_4 = new QLabel(ColorSensorConfig);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(300, 255, 111, 21));
        label_5 = new QLabel(ColorSensorConfig);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 380, 291, 21));
        label_6 = new QLabel(ColorSensorConfig);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(430, 350, 111, 41));
        layoutWidget1 = new QWidget(ColorSensorConfig);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 10, 451, 231));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        inputImg = new QLabel(layoutWidget1);
        inputImg->setObjectName(QStringLiteral("inputImg"));
        inputImg->setAutoFillBackground(true);

        horizontalLayout_2->addWidget(inputImg);

        outputImgLabel = new QLabel(layoutWidget1);
        outputImgLabel->setObjectName(QStringLiteral("outputImgLabel"));
        outputImgLabel->setAutoFillBackground(true);

        horizontalLayout_2->addWidget(outputImgLabel);

        layoutWidget2 = new QWidget(ColorSensorConfig);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 350, 251, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        DefineColorLabel = new QLabel(layoutWidget2);
        DefineColorLabel->setObjectName(QStringLiteral("DefineColorLabel"));

        horizontalLayout_8->addWidget(DefineColorLabel);

        DefinedColorOption = new QComboBox(layoutWidget2);
        DefinedColorOption->setObjectName(QStringLiteral("DefinedColorOption"));

        horizontalLayout_8->addWidget(DefinedColorOption);


        horizontalLayout_4->addLayout(horizontalLayout_8);

        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        okButtom->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();

        retranslateUi(ColorSensorConfig);

        QMetaObject::connectSlotsByName(ColorSensorConfig);
    } // setupUi

    void retranslateUi(QWidget *ColorSensorConfig)
    {
        ColorSensorConfig->setWindowTitle(QApplication::translate("ColorSensorConfig", "Form", 0));
        ColorMinLabel->setText(QApplication::translate("ColorSensorConfig", "ColorMin", 0));
        ColorMinValue->setText(QApplication::translate("ColorSensorConfig", "value", 0));
        ColorMaxLabel->setText(QApplication::translate("ColorSensorConfig", "ColorMax", 0));
        ColorMaxValue->setText(QApplication::translate("ColorSensorConfig", "value", 0));
        okButtom->setText(QApplication::translate("ColorSensorConfig", "OK", 0));
        label_3->setText(QApplication::translate("ColorSensorConfig", "Original", 0));
        label_4->setText(QApplication::translate("ColorSensorConfig", "Segmentation", 0));
        label_5->setText(QApplication::translate("ColorSensorConfig", "Use as cores definidas aqui para ajudar na sele\303\247\303\243o", 0));
        label_6->setText(QApplication::translate("ColorSensorConfig", "Clique para finalizar", 0));
        inputImg->setText(QString());
        outputImgLabel->setText(QString());
        DefineColorLabel->setText(QApplication::translate("ColorSensorConfig", "DefinedColor", 0));
    } // retranslateUi

};

namespace Ui {
    class ColorSensorConfig: public Ui_ColorSensorConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORSENSORCONFIG_H
