/********************************************************************************
** Form generated from reading UI file 'FilterComponent.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERCOMPONENT_H
#define UI_FILTERCOMPONENT_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilterComponent
{
public:
    QPushButton *activation_button;
    QLabel *type_label;
    QComboBox *type_comboBox;
    QLabel *slope_label;
    QComboBox *slope_comboBox;
    QDial *frequency_dial;
    QLabel *frequency_label;
    QDial *resonance_dial;
    QLabel *resonance_label;

    void setupUi(QWidget *FilterComponent)
    {
        if (FilterComponent->objectName().isEmpty())
            FilterComponent->setObjectName(QStringLiteral("FilterComponent"));
        FilterComponent->resize(120, 120);
        activation_button = new QPushButton(FilterComponent);
        activation_button->setObjectName(QStringLiteral("activation_button"));
        activation_button->setGeometry(QRect(0, 0, 75, 20));
        activation_button->setCheckable(true);
        type_label = new QLabel(FilterComponent);
        type_label->setObjectName(QStringLiteral("type_label"));
        type_label->setGeometry(QRect(0, 20, 40, 20));
        type_comboBox = new QComboBox(FilterComponent);
        type_comboBox->addItem(QString());
        type_comboBox->addItem(QString());
        type_comboBox->addItem(QString());
        type_comboBox->addItem(QString());
        type_comboBox->setObjectName(QStringLiteral("type_comboBox"));
        type_comboBox->setGeometry(QRect(40, 20, 80, 20));
        slope_label = new QLabel(FilterComponent);
        slope_label->setObjectName(QStringLiteral("slope_label"));
        slope_label->setGeometry(QRect(0, 40, 40, 20));
        slope_comboBox = new QComboBox(FilterComponent);
        slope_comboBox->addItem(QString());
        slope_comboBox->addItem(QString());
        slope_comboBox->addItem(QString());
        slope_comboBox->addItem(QString());
        slope_comboBox->addItem(QString());
        slope_comboBox->addItem(QString());
        slope_comboBox->setObjectName(QStringLiteral("slope_comboBox"));
        slope_comboBox->setGeometry(QRect(40, 40, 80, 20));
        frequency_dial = new QDial(FilterComponent);
        frequency_dial->setObjectName(QStringLiteral("frequency_dial"));
        frequency_dial->setGeometry(QRect(0, 80, 40, 40));
        frequency_dial->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        frequency_dial->setInvertedAppearance(false);
        frequency_dial->setInvertedControls(false);
        frequency_label = new QLabel(FilterComponent);
        frequency_label->setObjectName(QStringLiteral("frequency_label"));
        frequency_label->setGeometry(QRect(0, 60, 40, 20));
        frequency_label->setScaledContents(false);
        frequency_label->setAlignment(Qt::AlignCenter);
        resonance_dial = new QDial(FilterComponent);
        resonance_dial->setObjectName(QStringLiteral("resonance_dial"));
        resonance_dial->setGeometry(QRect(80, 80, 40, 40));
        resonance_dial->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        resonance_dial->setInvertedAppearance(false);
        resonance_dial->setInvertedControls(false);
        resonance_label = new QLabel(FilterComponent);
        resonance_label->setObjectName(QStringLiteral("resonance_label"));
        resonance_label->setGeometry(QRect(80, 60, 40, 20));
        resonance_label->setScaledContents(false);
        resonance_label->setAlignment(Qt::AlignCenter);

        retranslateUi(FilterComponent);

        QMetaObject::connectSlotsByName(FilterComponent);
    } // setupUi

    void retranslateUi(QWidget *FilterComponent)
    {
        FilterComponent->setWindowTitle(QApplication::translate("FilterComponent", "FilterComponent", nullptr));
        activation_button->setText(QApplication::translate("FilterComponent", "Filter 10", nullptr));
        type_label->setText(QApplication::translate("FilterComponent", "Type", nullptr));
        type_comboBox->setItemText(0, QApplication::translate("FilterComponent", "Low-pass", nullptr));
        type_comboBox->setItemText(1, QApplication::translate("FilterComponent", "Band-pass", nullptr));
        type_comboBox->setItemText(2, QApplication::translate("FilterComponent", "Notch", nullptr));
        type_comboBox->setItemText(3, QApplication::translate("FilterComponent", "High-pass", nullptr));

        slope_label->setText(QApplication::translate("FilterComponent", "Slope", nullptr));
        slope_comboBox->setItemText(0, QApplication::translate("FilterComponent", "12 dB", nullptr));
        slope_comboBox->setItemText(1, QApplication::translate("FilterComponent", "24 dB", nullptr));
        slope_comboBox->setItemText(2, QApplication::translate("FilterComponent", "36 dB", nullptr));
        slope_comboBox->setItemText(3, QApplication::translate("FilterComponent", "48 dB", nullptr));
        slope_comboBox->setItemText(4, QApplication::translate("FilterComponent", "72 dB", nullptr));
        slope_comboBox->setItemText(5, QApplication::translate("FilterComponent", "96 dB", nullptr));

#ifndef QT_NO_ACCESSIBILITY
        frequency_dial->setAccessibleName(QApplication::translate("FilterComponent", "Pitch", nullptr));
#endif // QT_NO_ACCESSIBILITY
        frequency_label->setText(QApplication::translate("FilterComponent", "F", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        resonance_dial->setAccessibleName(QApplication::translate("FilterComponent", "Pitch", nullptr));
#endif // QT_NO_ACCESSIBILITY
        resonance_label->setText(QApplication::translate("FilterComponent", "Q", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FilterComponent: public Ui_FilterComponent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERCOMPONENT_H
