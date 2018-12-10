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
    QLabel *listTitle_label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *OperatorsListComponent)
    {
        if (OperatorsListComponent->objectName().isEmpty())
            OperatorsListComponent->setObjectName(QStringLiteral("OperatorsListComponent"));
        OperatorsListComponent->resize(616, 258);
        listTitle_label = new QLabel(OperatorsListComponent);
        listTitle_label->setObjectName(QStringLiteral("listTitle_label"));
        listTitle_label->setGeometry(QRect(0, 0, 61, 31));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        listTitle_label->setFont(font);
        listTitle_label->setProperty("class", QVariant(QStringLiteral("list-title")));
        scrollArea = new QScrollArea(OperatorsListComponent);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 40, 611, 211));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 609, 209));
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(OperatorsListComponent);

        QMetaObject::connectSlotsByName(OperatorsListComponent);
    } // setupUi

    void retranslateUi(QWidget *OperatorsListComponent)
    {
        OperatorsListComponent->setWindowTitle(QApplication::translate("OperatorsListComponent", "OperatorsListComponent", nullptr));
        listTitle_label->setText(QApplication::translate("OperatorsListComponent", "OPS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OperatorsListComponent: public Ui_OperatorsListComponent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPERATORSLISTCOMPONENT_H
