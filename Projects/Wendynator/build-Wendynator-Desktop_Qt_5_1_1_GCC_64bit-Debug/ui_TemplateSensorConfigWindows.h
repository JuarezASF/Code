/********************************************************************************
** Form generated from reading UI file 'TemplateSensorConfigWindows.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPLATESENSORCONFIGWINDOWS_H
#define UI_TEMPLATESENSORCONFIGWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TemplateSensorConfigWindows
{
public:
    QLabel *templateImg;
    QLabel *templateInfoLabel;
    QPushButton *okButtom;
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *widthValue;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *highValue;
    QLabel *inputImg;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLabel *leftTopValueLabel;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLabel *rightBottomValueLabel;

    void setupUi(QWidget *TemplateSensorConfigWindows)
    {
        if (TemplateSensorConfigWindows->objectName().isEmpty())
            TemplateSensorConfigWindows->setObjectName(QStringLiteral("TemplateSensorConfigWindows"));
        TemplateSensorConfigWindows->resize(1026, 660);
        templateImg = new QLabel(TemplateSensorConfigWindows);
        templateImg->setObjectName(QStringLiteral("templateImg"));
        templateImg->setGeometry(QRect(710, 380, 191, 171));
        templateImg->setAutoFillBackground(true);
        templateInfoLabel = new QLabel(TemplateSensorConfigWindows);
        templateInfoLabel->setObjectName(QStringLiteral("templateInfoLabel"));
        templateInfoLabel->setGeometry(QRect(720, 340, 91, 20));
        okButtom = new QPushButton(TemplateSensorConfigWindows);
        okButtom->setObjectName(QStringLiteral("okButtom"));
        okButtom->setGeometry(QRect(740, 290, 80, 21));
        label = new QLabel(TemplateSensorConfigWindows);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(710, 120, 131, 21));
        layoutWidget = new QWidget(TemplateSensorConfigWindows);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(710, 150, 151, 51));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        widthValue = new QLabel(layoutWidget);
        widthValue->setObjectName(QStringLiteral("widthValue"));

        horizontalLayout->addWidget(widthValue);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        highValue = new QLabel(layoutWidget);
        highValue->setObjectName(QStringLiteral("highValue"));

        horizontalLayout_2->addWidget(highValue);


        verticalLayout->addLayout(horizontalLayout_2);

        inputImg = new QLabel(TemplateSensorConfigWindows);
        inputImg->setObjectName(QStringLiteral("inputImg"));
        inputImg->setGeometry(QRect(50, 40, 640, 480));
        inputImg->setAutoFillBackground(true);
        layoutWidget_2 = new QWidget(TemplateSensorConfigWindows);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(710, 220, 151, 51));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);

        leftTopValueLabel = new QLabel(layoutWidget_2);
        leftTopValueLabel->setObjectName(QStringLiteral("leftTopValueLabel"));

        horizontalLayout_3->addWidget(leftTopValueLabel);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_6 = new QLabel(layoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_4->addWidget(label_6);

        rightBottomValueLabel = new QLabel(layoutWidget_2);
        rightBottomValueLabel->setObjectName(QStringLiteral("rightBottomValueLabel"));

        horizontalLayout_4->addWidget(rightBottomValueLabel);


        verticalLayout_2->addLayout(horizontalLayout_4);


        retranslateUi(TemplateSensorConfigWindows);

        QMetaObject::connectSlotsByName(TemplateSensorConfigWindows);
    } // setupUi

    void retranslateUi(QWidget *TemplateSensorConfigWindows)
    {
        TemplateSensorConfigWindows->setWindowTitle(QApplication::translate("TemplateSensorConfigWindows", "Form", 0));
        templateImg->setText(QString());
        templateInfoLabel->setText(QApplication::translate("TemplateSensorConfigWindows", "Template Atual", 0));
        okButtom->setText(QApplication::translate("TemplateSensorConfigWindows", "Ok", 0));
        label->setText(QApplication::translate("TemplateSensorConfigWindows", "template properties", 0));
        label_3->setText(QApplication::translate("TemplateSensorConfigWindows", "width", 0));
        widthValue->setText(QApplication::translate("TemplateSensorConfigWindows", "0", 0));
        label_4->setText(QApplication::translate("TemplateSensorConfigWindows", "heigh", 0));
        highValue->setText(QApplication::translate("TemplateSensorConfigWindows", "0", 0));
        inputImg->setText(QString());
        label_5->setText(QApplication::translate("TemplateSensorConfigWindows", "leftTop", 0));
        leftTopValueLabel->setText(QApplication::translate("TemplateSensorConfigWindows", "0", 0));
        label_6->setText(QApplication::translate("TemplateSensorConfigWindows", "rightBottom", 0));
        rightBottomValueLabel->setText(QApplication::translate("TemplateSensorConfigWindows", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class TemplateSensorConfigWindows: public Ui_TemplateSensorConfigWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPLATESENSORCONFIGWINDOWS_H
