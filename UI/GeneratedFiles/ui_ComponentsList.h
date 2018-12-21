/********************************************************************************
** Form generated from reading UI file 'ComponentsList.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPONENTSLIST_H
#define UI_COMPONENTSLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ComponentsList
{
public:
    QLabel *listTitle_label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *ComponentsList)
    {
        if (ComponentsList->objectName().isEmpty())
            ComponentsList->setObjectName(QStringLiteral("ComponentsList"));
        ComponentsList->resize(500, 80);
        listTitle_label = new QLabel(ComponentsList);
        listTitle_label->setObjectName(QStringLiteral("listTitle_label"));
        listTitle_label->setGeometry(QRect(0, 0, 500, 30));
        scrollArea = new QScrollArea(ComponentsList);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 30, 500, 50));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 498, 48));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(ComponentsList);

        QMetaObject::connectSlotsByName(ComponentsList);
    } // setupUi

    void retranslateUi(QWidget *ComponentsList)
    {
        ComponentsList->setWindowTitle(QApplication::translate("ComponentsList", "ComponentsList", nullptr));
        listTitle_label->setText(QApplication::translate("ComponentsList", "TITLE", nullptr));
        listTitle_label->setProperty("class", QVariant(QApplication::translate("ComponentsList", "title", nullptr)));
    } // retranslateUi

};

namespace Ui {
    class ComponentsList: public Ui_ComponentsList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPONENTSLIST_H
