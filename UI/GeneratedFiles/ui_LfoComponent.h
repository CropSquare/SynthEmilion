/********************************************************************************
** Form generated from reading UI file 'LfoComponent.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LFOCOMPONENT_H
#define UI_LFOCOMPONENT_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LfoComponent
{
public:
    QPushButton *activation_button;
    QComboBox *trigger_comboBox;
    QDial *gain_dial;
    QDial *rate_dial;
    QLabel *rate_label;
    QLabel *offset_label;
    QDial *offset_dial;
    QLabel *gain_label;
    QPushButton *sync_pushButton;
    QLabel *sync_label;
    QLabel *trigger_label;

    void setupUi(QWidget *LfoComponent)
    {
        if (LfoComponent->objectName().isEmpty())
            LfoComponent->setObjectName(QStringLiteral("LfoComponent"));
        LfoComponent->resize(120, 120);
        activation_button = new QPushButton(LfoComponent);
        activation_button->setObjectName(QStringLiteral("activation_button"));
        activation_button->setGeometry(QRect(0, 0, 75, 20));
        activation_button->setCheckable(true);
        trigger_comboBox = new QComboBox(LfoComponent);
        trigger_comboBox->addItem(QString());
        trigger_comboBox->addItem(QString());
        trigger_comboBox->addItem(QString());
        trigger_comboBox->setObjectName(QStringLiteral("trigger_comboBox"));
        trigger_comboBox->setGeometry(QRect(50, 40, 70, 20));
        gain_dial = new QDial(LfoComponent);
        gain_dial->setObjectName(QStringLiteral("gain_dial"));
        gain_dial->setGeometry(QRect(40, 80, 40, 40));
        gain_dial->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gain_dial->setInvertedAppearance(false);
        gain_dial->setInvertedControls(false);
        rate_dial = new QDial(LfoComponent);
        rate_dial->setObjectName(QStringLiteral("rate_dial"));
        rate_dial->setGeometry(QRect(0, 80, 40, 40));
        rate_dial->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        rate_dial->setInvertedAppearance(false);
        rate_dial->setInvertedControls(false);
        rate_label = new QLabel(LfoComponent);
        rate_label->setObjectName(QStringLiteral("rate_label"));
        rate_label->setGeometry(QRect(0, 60, 40, 20));
        rate_label->setScaledContents(false);
        rate_label->setAlignment(Qt::AlignCenter);
        offset_label = new QLabel(LfoComponent);
        offset_label->setObjectName(QStringLiteral("offset_label"));
        offset_label->setGeometry(QRect(80, 60, 40, 20));
        offset_label->setAlignment(Qt::AlignCenter);
        offset_dial = new QDial(LfoComponent);
        offset_dial->setObjectName(QStringLiteral("offset_dial"));
        offset_dial->setGeometry(QRect(80, 80, 40, 40));
        offset_dial->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        offset_dial->setInvertedAppearance(false);
        offset_dial->setInvertedControls(false);
        gain_label = new QLabel(LfoComponent);
        gain_label->setObjectName(QStringLiteral("gain_label"));
        gain_label->setGeometry(QRect(40, 60, 40, 20));
        gain_label->setAlignment(Qt::AlignCenter);
        sync_pushButton = new QPushButton(LfoComponent);
        sync_pushButton->setObjectName(QStringLiteral("sync_pushButton"));
        sync_pushButton->setGeometry(QRect(50, 20, 20, 20));
        sync_pushButton->setCheckable(true);
        sync_label = new QLabel(LfoComponent);
        sync_label->setObjectName(QStringLiteral("sync_label"));
        sync_label->setGeometry(QRect(0, 20, 40, 20));
        trigger_label = new QLabel(LfoComponent);
        trigger_label->setObjectName(QStringLiteral("trigger_label"));
        trigger_label->setGeometry(QRect(0, 40, 40, 20));

        retranslateUi(LfoComponent);

        QMetaObject::connectSlotsByName(LfoComponent);
    } // setupUi

    void retranslateUi(QWidget *LfoComponent)
    {
        LfoComponent->setWindowTitle(QApplication::translate("LfoComponent", "LfoComponent", nullptr));
        activation_button->setText(QApplication::translate("LfoComponent", "LFO 10", nullptr));
        trigger_comboBox->setItemText(0, QApplication::translate("LfoComponent", "Startup", nullptr));
        trigger_comboBox->setItemText(1, QApplication::translate("LfoComponent", "On note", nullptr));
        trigger_comboBox->setItemText(2, QApplication::translate("LfoComponent", "All notes", nullptr));

#ifndef QT_NO_ACCESSIBILITY
        gain_dial->setAccessibleName(QApplication::translate("LfoComponent", "Pan", nullptr));
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        rate_dial->setAccessibleName(QApplication::translate("LfoComponent", "Pitch", nullptr));
#endif // QT_NO_ACCESSIBILITY
        rate_label->setText(QApplication::translate("LfoComponent", "Rate", nullptr));
        offset_label->setText(QApplication::translate("LfoComponent", "Offset", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        offset_dial->setAccessibleName(QApplication::translate("LfoComponent", "Vol", nullptr));
#endif // QT_NO_ACCESSIBILITY
        gain_label->setText(QApplication::translate("LfoComponent", "Gain", nullptr));
        sync_pushButton->setText(QString());
        sync_label->setText(QApplication::translate("LfoComponent", "Sync", nullptr));
        trigger_label->setText(QApplication::translate("LfoComponent", "Trigger", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LfoComponent: public Ui_LfoComponent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LFOCOMPONENT_H
