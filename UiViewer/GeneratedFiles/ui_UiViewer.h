/********************************************************************************
** Form generated from reading UI file 'UiViewer.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIVIEWER_H
#define UI_UIVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UiViewerClass
{
public:
    QWidget *centralWidget;

    void setupUi(QMainWindow *UiViewerClass)
    {
        if (UiViewerClass->objectName().isEmpty())
            UiViewerClass->setObjectName(QStringLiteral("UiViewerClass"));
        UiViewerClass->resize(600, 400);
        centralWidget = new QWidget(UiViewerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        UiViewerClass->setCentralWidget(centralWidget);

        retranslateUi(UiViewerClass);

        QMetaObject::connectSlotsByName(UiViewerClass);
    } // setupUi

    void retranslateUi(QMainWindow *UiViewerClass)
    {
        UiViewerClass->setWindowTitle(QApplication::translate("UiViewerClass", "UiViewer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UiViewerClass: public Ui_UiViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIVIEWER_H
