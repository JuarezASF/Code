/********************************************************************************
** Form generated from reading UI file 'PainelControle.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAINELCONTROLE_H
#define UI_PAINELCONTROLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PainelControle
{
public:

    void setupUi(QWidget *PainelControle)
    {
        if (PainelControle->objectName().isEmpty())
            PainelControle->setObjectName(QStringLiteral("PainelControle"));
        PainelControle->resize(504, 407);

        retranslateUi(PainelControle);

        QMetaObject::connectSlotsByName(PainelControle);
    } // setupUi

    void retranslateUi(QWidget *PainelControle)
    {
        PainelControle->setWindowTitle(QApplication::translate("PainelControle", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class PainelControle: public Ui_PainelControle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAINELCONTROLE_H
