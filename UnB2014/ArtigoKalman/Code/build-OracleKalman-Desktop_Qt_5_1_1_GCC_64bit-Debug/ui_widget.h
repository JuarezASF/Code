/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton;
    QTextEdit *logText;
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
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *DefineColorLabel;
    QComboBox *DefinedColorOption;
    QPushButton *addTotrackingButtom;
    QLabel *currentSegmentationImg;
    QComboBox *trackedColorsList;
    QPushButton *deleteButtom;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *InputImg;
    QLabel *OutputImg;
    QWidget *layoutWidget_3;
    QVBoxLayout *FuturePastLayout;
    QCheckBox *futureButtom;
    QCheckBox *pastButtom;
    QPushButton *ClearPastButtom;
    QPushButton *BorrarButtom;
    QComboBox *SizeOfGaussian;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *raioLabel;
    QLabel *raioValueLabel;
    QSlider *raioSlider;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *SaveLabel;
    QLineEdit *SaveLineEdit;
    QPushButton *saveButtom;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *SaveInputLabel;
    QLineEdit *SaveInputEdit;
    QPushButton *SaveInputButtom;
    QPushButton *gnuplotButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1234, 536);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(490, 460, 91, 51));
        logText = new QTextEdit(Widget);
        logText->setObjectName(QStringLiteral("logText"));
        logText->setGeometry(QRect(30, 390, 451, 121));
        logText->setReadOnly(true);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(760, 80, 411, 58));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        ColorMinLabel = new QLabel(layoutWidget);
        ColorMinLabel->setObjectName(QStringLiteral("ColorMinLabel"));

        horizontalLayout_3->addWidget(ColorMinLabel);

        ColorMinChannelOption = new QComboBox(layoutWidget);
        ColorMinChannelOption->setObjectName(QStringLiteral("ColorMinChannelOption"));

        horizontalLayout_3->addWidget(ColorMinChannelOption);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
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
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        ColorMaxLabel = new QLabel(layoutWidget);
        ColorMaxLabel->setObjectName(QStringLiteral("ColorMaxLabel"));

        horizontalLayout_6->addWidget(ColorMaxLabel);

        ColorMaxChannelOption = new QComboBox(layoutWidget);
        ColorMaxChannelOption->setObjectName(QStringLiteral("ColorMaxChannelOption"));

        horizontalLayout_6->addWidget(ColorMaxChannelOption);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
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

        layoutWidget_2 = new QWidget(Widget);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(760, 140, 251, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        DefineColorLabel = new QLabel(layoutWidget_2);
        DefineColorLabel->setObjectName(QStringLiteral("DefineColorLabel"));

        horizontalLayout_8->addWidget(DefineColorLabel);

        DefinedColorOption = new QComboBox(layoutWidget_2);
        DefinedColorOption->setObjectName(QStringLiteral("DefinedColorOption"));

        horizontalLayout_8->addWidget(DefinedColorOption);


        horizontalLayout_4->addLayout(horizontalLayout_8);

        addTotrackingButtom = new QPushButton(Widget);
        addTotrackingButtom->setObjectName(QStringLiteral("addTotrackingButtom"));
        addTotrackingButtom->setGeometry(QRect(1020, 240, 161, 41));
        currentSegmentationImg = new QLabel(Widget);
        currentSegmentationImg->setObjectName(QStringLiteral("currentSegmentationImg"));
        currentSegmentationImg->setGeometry(QRect(760, 190, 251, 181));
        currentSegmentationImg->setAutoFillBackground(true);
        trackedColorsList = new QComboBox(Widget);
        trackedColorsList->setObjectName(QStringLiteral("trackedColorsList"));
        trackedColorsList->setGeometry(QRect(780, 40, 141, 23));
        deleteButtom = new QPushButton(Widget);
        deleteButtom->setObjectName(QStringLiteral("deleteButtom"));
        deleteButtom->setGeometry(QRect(930, 40, 80, 23));
        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 20, 711, 311));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        InputImg = new QLabel(layoutWidget1);
        InputImg->setObjectName(QStringLiteral("InputImg"));
        InputImg->setMouseTracking(false);
        InputImg->setAutoFillBackground(true);

        horizontalLayout_2->addWidget(InputImg);

        OutputImg = new QLabel(layoutWidget1);
        OutputImg->setObjectName(QStringLiteral("OutputImg"));
        OutputImg->setMouseTracking(false);
        OutputImg->setAutoFillBackground(true);

        horizontalLayout_2->addWidget(OutputImg);

        layoutWidget_3 = new QWidget(Widget);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(491, 371, 81, 52));
        FuturePastLayout = new QVBoxLayout(layoutWidget_3);
        FuturePastLayout->setSpacing(6);
        FuturePastLayout->setContentsMargins(11, 11, 11, 11);
        FuturePastLayout->setObjectName(QStringLiteral("FuturePastLayout"));
        FuturePastLayout->setContentsMargins(0, 0, 0, 0);
        futureButtom = new QCheckBox(layoutWidget_3);
        futureButtom->setObjectName(QStringLiteral("futureButtom"));

        FuturePastLayout->addWidget(futureButtom);

        pastButtom = new QCheckBox(layoutWidget_3);
        pastButtom->setObjectName(QStringLiteral("pastButtom"));
        pastButtom->setChecked(false);

        FuturePastLayout->addWidget(pastButtom);

        ClearPastButtom = new QPushButton(Widget);
        ClearPastButtom->setObjectName(QStringLiteral("ClearPastButtom"));
        ClearPastButtom->setGeometry(QRect(490, 430, 80, 23));
        BorrarButtom = new QPushButton(Widget);
        BorrarButtom->setObjectName(QStringLiteral("BorrarButtom"));
        BorrarButtom->setGeometry(QRect(594, 370, 80, 23));
        SizeOfGaussian = new QComboBox(Widget);
        SizeOfGaussian->setObjectName(QStringLiteral("SizeOfGaussian"));
        SizeOfGaussian->setGeometry(QRect(680, 370, 79, 23));
        layoutWidget_4 = new QWidget(Widget);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(590, 410, 311, 17));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        raioLabel = new QLabel(layoutWidget_4);
        raioLabel->setObjectName(QStringLiteral("raioLabel"));

        horizontalLayout_5->addWidget(raioLabel);

        raioValueLabel = new QLabel(layoutWidget_4);
        raioValueLabel->setObjectName(QStringLiteral("raioValueLabel"));

        horizontalLayout_5->addWidget(raioValueLabel);

        raioSlider = new QSlider(layoutWidget_4);
        raioSlider->setObjectName(QStringLiteral("raioSlider"));
        raioSlider->setMaximum(100);
        raioSlider->setValue(20);
        raioSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(raioSlider);

        layoutWidget_5 = new QWidget(Widget);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(590, 440, 491, 25));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        SaveLabel = new QLabel(layoutWidget_5);
        SaveLabel->setObjectName(QStringLiteral("SaveLabel"));

        horizontalLayout_9->addWidget(SaveLabel);

        SaveLineEdit = new QLineEdit(layoutWidget_5);
        SaveLineEdit->setObjectName(QStringLiteral("SaveLineEdit"));

        horizontalLayout_9->addWidget(SaveLineEdit);

        saveButtom = new QPushButton(layoutWidget_5);
        saveButtom->setObjectName(QStringLiteral("saveButtom"));

        horizontalLayout_9->addWidget(saveButtom);

        layoutWidget_6 = new QWidget(Widget);
        layoutWidget_6->setObjectName(QStringLiteral("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(590, 470, 491, 25));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        SaveInputLabel = new QLabel(layoutWidget_6);
        SaveInputLabel->setObjectName(QStringLiteral("SaveInputLabel"));

        horizontalLayout_10->addWidget(SaveInputLabel);

        SaveInputEdit = new QLineEdit(layoutWidget_6);
        SaveInputEdit->setObjectName(QStringLiteral("SaveInputEdit"));

        horizontalLayout_10->addWidget(SaveInputEdit);

        SaveInputButtom = new QPushButton(layoutWidget_6);
        SaveInputButtom->setObjectName(QStringLiteral("SaveInputButtom"));

        horizontalLayout_10->addWidget(SaveInputButtom);

        gnuplotButton = new QPushButton(Widget);
        gnuplotButton->setObjectName(QStringLiteral("gnuplotButton"));
        gnuplotButton->setGeometry(QRect(490, 340, 80, 23));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        pushButton->setText(QApplication::translate("Widget", "Clear Log", 0));
        ColorMinLabel->setText(QApplication::translate("Widget", "ColorMin", 0));
        ColorMinValue->setText(QApplication::translate("Widget", "value", 0));
        ColorMaxLabel->setText(QApplication::translate("Widget", "ColorMax", 0));
        ColorMaxValue->setText(QApplication::translate("Widget", "value", 0));
        DefineColorLabel->setText(QApplication::translate("Widget", "DefinedColor", 0));
        addTotrackingButtom->setText(QApplication::translate("Widget", "Add Color to Tracking", 0));
        currentSegmentationImg->setText(QString());
        deleteButtom->setText(QApplication::translate("Widget", "delete", 0));
        InputImg->setText(QString());
        OutputImg->setText(QString());
        futureButtom->setText(QApplication::translate("Widget", "Future", 0));
        pastButtom->setText(QApplication::translate("Widget", "Past", 0));
        ClearPastButtom->setText(QApplication::translate("Widget", "Clear Past", 0));
        BorrarButtom->setText(QApplication::translate("Widget", "Borrar", 0));
        raioLabel->setText(QApplication::translate("Widget", "raio", 0));
        raioValueLabel->setText(QApplication::translate("Widget", "30", 0));
        SaveLabel->setText(QApplication::translate("Widget", "output save to: ", 0));
        saveButtom->setText(QApplication::translate("Widget", "save", 0));
        SaveInputLabel->setText(QApplication::translate("Widget", "input save to: ", 0));
        SaveInputButtom->setText(QApplication::translate("Widget", "save", 0));
        gnuplotButton->setText(QApplication::translate("Widget", "Gnuplot", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
