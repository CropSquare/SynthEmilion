/********************************************************************************
** Form generated from reading UI file 'OperatorsListComponent.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPERATORSLISTCOMPONENT_H
#define UI_OPERATORSLISTCOMPONENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OperatorsListComponent
{
public:
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *OperatorsListComponent)
    {
        if (OperatorsListComponent->objectName().isEmpty())
            OperatorsListComponent->setObjectName(QStringLiteral("OperatorsListComponent"));
        OperatorsListComponent->resize(616, 258);
        label = new QLabel(OperatorsListComponent);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 61, 31));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        scrollArea = new QScrollArea(OperatorsListComponent);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 40, 611, 211));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 609, 209));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(OperatorsListComponent);

        QMetaObject::connectSlotsByName(OperatorsListComponent);
    } // setupUi

    void retranslateUi(QWidget *OperatorsListComponent)
    {
        OperatorsListComponent->setWindowTitle(QApplication::translate("OperatorsListComponent", "OperatorsListComponent", nullptr));
        label->setText(QApplication::translate("OperatorsListComponent", "OPS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OperatorsListComponent: public Ui_OperatorsListComponent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPERATORSLISTCOMPONENT_H
