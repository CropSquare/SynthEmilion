/********************************************************************************
** Form generated from reading UI file 'EnvelopeComponent.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENVELOPECOMPONENT_H
#define UI_ENVELOPECOMPONENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EnvelopeComponent
{
public:
    QSlider *attack_slider;
    QLabel *attack_label;
    QPushButton *activation_button;
    QSlider *decay_slider;
    QLabel *decay_label;
    QSlider *sustain_slider;
    QLabel *sustain_label;
    QSlider *release_slider;
    QLabel *release_label;
    QDial *attackBend_dial;
    QDial *decayBend_dial;
    QDial *releaseBend_dial;

    void setupUi(QWidget *EnvelopeComponent)
    {
        if (EnvelopeComponent->objectName().isEmpty())
            EnvelopeComponent->setObjectName(QStringLiteral("EnvelopeComponent"));
        EnvelopeComponent->resize(120, 170);
        attack_slider = new QSlider(EnvelopeComponent);
        attack_slider->setObjectName(QStringLiteral("attack_slider"));
        attack_slider->setGeometry(QRect(5, 40, 20, 100));
        attack_slider->setOrientation(Qt::Vertical);
        attack_label = new QLabel(EnvelopeComponent);
        attack_label->setObjectName(QStringLiteral("attack_label"));
        attack_label->setGeometry(QRect(0, 20, 30, 20));
        attack_label->setAlignment(Qt::AlignCenter);
        activation_button = new QPushButton(EnvelopeComponent);
        activation_button->setObjectName(QStringLiteral("activation_button"));
        activation_button->setGeometry(QRect(0, 0, 75, 20));
        activation_button->setCheckable(true);
        decay_slider = new QSlider(EnvelopeComponent);
        decay_slider->setObjectName(QStringLiteral("decay_slider"));
        decay_slider->setGeometry(QRect(35, 40, 20, 100));
        decay_slider->setOrientation(Qt::Vertical);
        decay_label = new QLabel(EnvelopeComponent);
        decay_label->setObjectName(QStringLiteral("decay_label"));
        decay_label->setGeometry(QRect(30, 20, 30, 20));
        decay_label->setAlignment(Qt::AlignCenter);
        sustain_slider = new QSlider(EnvelopeComponent);
        sustain_slider->setObjectName(QStringLiteral("sustain_slider"));
        sustain_slider->setGeometry(QRect(65, 40, 20, 100));
        sustain_slider->setOrientation(Qt::Vertical);
        sustain_label = new QLabel(EnvelopeComponent);
        sustain_label->setObjectName(QStringLiteral("sustain_label"));
        sustain_label->setGeometry(QRect(60, 20, 30, 20));
        sustain_label->setAlignment(Qt::AlignCenter);
        release_slider = new QSlider(EnvelopeComponent);
        release_slider->setObjectName(QStringLiteral("release_slider"));
        release_slider->setGeometry(QRect(95, 40, 20, 100));
        release_slider->setOrientation(Qt::Vertical);
        release_label = new QLabel(EnvelopeComponent);
        release_label->setObjectName(QStringLiteral("release_label"));
        release_label->setGeometry(QRect(90, 20, 30, 20));
        release_label->setAlignment(Qt::AlignCenter);
        attackBend_dial = new QDial(EnvelopeComponent);
        attackBend_dial->setObjectName(QStringLiteral("attackBend_dial"));
        attackBend_dial->setGeometry(QRect(0, 140, 30, 30));
        decayBend_dial = new QDial(EnvelopeComponent);
        decayBend_dial->setObjectName(QStringLiteral("decayBend_dial"));
        decayBend_dial->setGeometry(QRect(30, 140, 30, 30));
        releaseBend_dial = new QDial(EnvelopeComponent);
        releaseBend_dial->setObjectName(QStringLiteral("releaseBend_dial"));
        releaseBend_dial->setGeometry(QRect(90, 140, 30, 30));

        retranslateUi(EnvelopeComponent);

        QMetaObject::connectSlotsByName(EnvelopeComponent);
    } // setupUi

    void retranslateUi(QWidget *EnvelopeComponent)
    {
        EnvelopeComponent->setWindowTitle(QApplication::translate("EnvelopeComponent", "EnvelopeComponent", nullptr));
        attack_label->setText(QApplication::translate("EnvelopeComponent", "A", nullptr));
        activation_button->setText(QApplication::translate("EnvelopeComponent", "Envelope 10", nullptr));
        decay_label->setText(QApplication::translate("EnvelopeComponent", "D", nullptr));
        sustain_label->setText(QApplication::translate("EnvelopeComponent", "S", nullptr));
        release_label->setText(QApplication::translate("EnvelopeComponent", "R", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnvelopeComponent: public Ui_EnvelopeComponent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENVELOPECOMPONENT_H
