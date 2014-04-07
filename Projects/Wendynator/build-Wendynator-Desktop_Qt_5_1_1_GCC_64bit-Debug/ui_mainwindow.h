/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *logText;
    QLabel *InputImg;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *sensorTypeLabel;
    QComboBox *SensorTypeComboBox;
    QPushButton *SensorTypeSetButton;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(756, 537);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        logText = new QTextEdit(centralWidget);
        logText->setObjectName(QStringLiteral("logText"));
        logText->setGeometry(QRect(10, 340, 451, 121));
        logText->setReadOnly(true);
        InputImg = new QLabel(centralWidget);
        InputImg->setObjectName(QStringLiteral("InputImg"));
        InputImg->setGeometry(QRect(20, 10, 391, 311));
        InputImg->setMouseTracking(false);
        InputImg->setAutoFillBackground(true);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(440, 30, 234, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sensorTypeLabel = new QLabel(layoutWidget);
        sensorTypeLabel->setObjectName(QStringLiteral("sensorTypeLabel"));

        horizontalLayout->addWidget(sensorTypeLabel);

        SensorTypeComboBox = new QComboBox(layoutWidget);
        SensorTypeComboBox->setObjectName(QStringLiteral("SensorTypeComboBox"));

        horizontalLayout->addWidget(SensorTypeComboBox);

        SensorTypeSetButton = new QPushButton(layoutWidget);
        SensorTypeSetButton->setObjectName(QStringLiteral("SensorTypeSetButton"));

        horizontalLayout->addWidget(SensorTypeSetButton);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(470, 390, 91, 51));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 756, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Wendynator", 0));
        InputImg->setText(QString());
        sensorTypeLabel->setText(QApplication::translate("MainWindow", "SensorType", 0));
        SensorTypeSetButton->setText(QApplication::translate("MainWindow", "set", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Clear Log", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
