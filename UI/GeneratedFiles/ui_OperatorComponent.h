/********************************************************************************
** Form generated from reading UI file 'OperatorComponent.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPERATORCOMPONENT_H
#define UI_OPERATORCOMPONENT_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OperatorComponent
{
public:
    QDial *pitch_dial;
    QDial *pan_dial;
    QDial *vol_dial;
    QLabel *pitch_label;
    QLabel *pan_label;
    QLabel *vol_label;
    QPushButton *activation_button;

    void setupUi(QWidget *OperatorComponent)
    {
        if (OperatorComponent->objectName().isEmpty())
            OperatorComponent->setObjectName(QStringLiteral("OperatorComponent"));
        OperatorComponent->resize(120, 80);
        pitch_dial = new QDial(OperatorComponent);
        pitch_dial->setObjectName(QStringLiteral("pitch_dial"));
        pitch_dial->setGeometry(QRect(0, 40, 40, 40));
        pitch_dial->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        pitch_dial->setMinimum(-6100);
        pitch_dial->setMaximum(6100);
        pitch_dial->setInvertedAppearance(false);
        pitch_dial->setInvertedControls(false);
        pan_dial = new QDial(OperatorComponent);
        pan_dial->setObjectName(QStringLiteral("pan_dial"));
        pan_dial->setGeometry(QRect(40, 40, 40, 40));
        pan_dial->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        pan_dial->setMinimum(-100);
        pan_dial->setMaximum(100);
        pan_dial->setInvertedAppearance(false);
        pan_dial->setInvertedControls(false);
        vol_dial = new QDial(OperatorComponent);
        vol_dial->setObjectName(QStringLiteral("vol_dial"));
        vol_dial->setGeometry(QRect(80, 40, 40, 40));
        vol_dial->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        vol_dial->setMaximum(100);
        vol_dial->setValue(50);
        vol_dial->setInvertedAppearance(false);
        vol_dial->setInvertedControls(false);
        pitch_label = new QLabel(OperatorComponent);
        pitch_label->setObjectName(QStringLiteral("pitch_label"));
        pitch_label->setGeometry(QRect(0, 20, 40, 20));
        pitch_label->setScaledContents(false);
        pitch_label->setAlignment(Qt::AlignCenter);
        pan_label = new QLabel(OperatorComponent);
        pan_label->setObjectName(QStringLiteral("pan_label"));
        pan_label->setGeometry(QRect(40, 20, 40, 20));
        pan_label->setAlignment(Qt::AlignCenter);
        vol_label = new QLabel(OperatorComponent);
        vol_label->setObjectName(QStringLiteral("vol_label"));
        vol_label->setGeometry(QRect(80, 20, 40, 20));
        vol_label->setAlignment(Qt::AlignCenter);
        activation_button = new QPushButton(OperatorComponent);
        activation_button->setObjectName(QStringLiteral("activation_button"));
        activation_button->setGeometry(QRect(0, 0, 75, 20));
        activation_button->setCheckable(true);

        retranslateUi(OperatorComponent);

        QMetaObject::connectSlotsByName(OperatorComponent);
    } // setupUi

    void retranslateUi(QWidget *OperatorComponent)
    {
        OperatorComponent->setWindowTitle(QApplication::translate("OperatorComponent", "OperatorComponent", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        pitch_dial->setAccessibleName(QApplication::translate("OperatorComponent", "Pitch", nullptr));
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        pan_dial->setAccessibleName(QApplication::translate("OperatorComponent", "Pan", nullptr));
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        vol_dial->setAccessibleName(QApplication::translate("OperatorComponent", "Vol", nullptr));
#endif // QT_NO_ACCESSIBILITY
        pitch_label->setText(QApplication::translate("OperatorComponent", "Pitch", nullptr));
        pan_label->setText(QApplication::translate("OperatorComponent", "Pan", nullptr));
        vol_label->setText(QApplication::translate("OperatorComponent", "Vol", nullptr));
        activation_button->setText(QApplication::translate("OperatorComponent", "Operator 10", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OperatorComponent: public Ui_OperatorComponent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPERATORCOMPONENT_H
