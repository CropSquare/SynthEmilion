/********************************************************************************
** Form generated from reading UI file 'OperatorPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPERATORPANEL_H
#define UI_OPERATORPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OperatorPanel
{
public:

    void setupUi(QWidget *OperatorPanel)
    {
        if (OperatorPanel->objectName().isEmpty())
            OperatorPanel->setObjectName(QStringLiteral("OperatorPanel"));
        OperatorPanel->resize(400, 300);

        retranslateUi(OperatorPanel);

        QMetaObject::connectSlotsByName(OperatorPanel);
    } // setupUi

    void retranslateUi(QWidget *OperatorPanel)
    {
        OperatorPanel->setWindowTitle(QApplication::translate("OperatorPanel", "OperatorPanel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OperatorPanel: public Ui_OperatorPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPERATORPANEL_H
