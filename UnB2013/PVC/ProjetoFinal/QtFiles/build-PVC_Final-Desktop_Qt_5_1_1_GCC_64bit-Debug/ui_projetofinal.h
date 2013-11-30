/********************************************************************************
** Form generated from reading UI file 'projetofinal.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJETOFINAL_H
#define UI_PROJETOFINAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjetoFinal
{
public:
    QWidget *centralWidget;
    QPlainTextEdit *logText;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *inputImg;
    QLabel *outputImg;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QCheckBox *pastButtom;
    QCheckBox *futureButtom;
    QCheckBox *checkBox_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProjetoFinal)
    {
        if (ProjetoFinal->objectName().isEmpty())
            ProjetoFinal->setObjectName(QStringLiteral("ProjetoFinal"));
        ProjetoFinal->resize(923, 702);
        centralWidget = new QWidget(ProjetoFinal);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        logText = new QPlainTextEdit(centralWidget);
        logText->setObjectName(QStringLiteral("logText"));
        logText->setGeometry(QRect(240, 380, 521, 101));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(110, 0, 681, 371));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        inputImg = new QLabel(widget);
        inputImg->setObjectName(QStringLiteral("inputImg"));
        inputImg->setAutoFillBackground(true);

        horizontalLayout->addWidget(inputImg);

        outputImg = new QLabel(widget);
        outputImg->setObjectName(QStringLiteral("outputImg"));
        outputImg->setAutoFillBackground(true);

        horizontalLayout->addWidget(outputImg);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(120, 390, 87, 77));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pastButtom = new QCheckBox(widget1);
        pastButtom->setObjectName(QStringLiteral("pastButtom"));
        pastButtom->setChecked(false);

        verticalLayout->addWidget(pastButtom);

        futureButtom = new QCheckBox(widget1);
        futureButtom->setObjectName(QStringLiteral("futureButtom"));

        verticalLayout->addWidget(futureButtom);

        checkBox_3 = new QCheckBox(widget1);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        verticalLayout->addWidget(checkBox_3);

        ProjetoFinal->setCentralWidget(centralWidget);
        inputImg->raise();
        outputImg->raise();
        logText->raise();
        pastButtom->raise();
        inputImg->raise();
        pastButtom->raise();
        futureButtom->raise();
        checkBox_3->raise();
        menuBar = new QMenuBar(ProjetoFinal);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 923, 20));
        ProjetoFinal->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProjetoFinal);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ProjetoFinal->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ProjetoFinal);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ProjetoFinal->setStatusBar(statusBar);

        retranslateUi(ProjetoFinal);

        QMetaObject::connectSlotsByName(ProjetoFinal);
    } // setupUi

    void retranslateUi(QMainWindow *ProjetoFinal)
    {
        ProjetoFinal->setWindowTitle(QApplication::translate("ProjetoFinal", "ProjetoFinal", 0));
        inputImg->setText(QString());
        outputImg->setText(QString());
        pastButtom->setText(QApplication::translate("ProjetoFinal", "Past", 0));
        futureButtom->setText(QApplication::translate("ProjetoFinal", "Future", 0));
        checkBox_3->setText(QApplication::translate("ProjetoFinal", "CheckBox", 0));
    } // retranslateUi

};

namespace Ui {
    class ProjetoFinal: public Ui_ProjetoFinal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJETOFINAL_H
