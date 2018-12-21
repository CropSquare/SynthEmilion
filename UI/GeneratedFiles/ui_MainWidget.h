/********************************************************************************
** Form generated from reading UI file 'MainWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QLabel *paramChangeLabel;
    QLabel *activeCompLabel;
    QPushButton *reloadQss_button;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QStringLiteral("MainWidget"));
        MainWidget->resize(628, 380);
        paramChangeLabel = new QLabel(MainWidget);
        paramChangeLabel->setObjectName(QStringLiteral("paramChangeLabel"));
        paramChangeLabel->setGeometry(QRect(10, 0, 541, 16));
        activeCompLabel = new QLabel(MainWidget);
        activeCompLabel->setObjectName(QStringLiteral("activeCompLabel"));
        activeCompLabel->setGeometry(QRect(10, 20, 541, 16));
        reloadQss_button = new QPushButton(MainWidget);
        reloadQss_button->setObjectName(QStringLiteral("reloadQss_button"));
        reloadQss_button->setGeometry(QRect(554, 0, 70, 40));

        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", nullptr));
        paramChangeLabel->setText(QApplication::translate("MainWidget", "Param", nullptr));
        activeCompLabel->setText(QApplication::translate("MainWidget", "Active component", nullptr));
        reloadQss_button->setText(QApplication::translate("MainWidget", "Reload QSS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
