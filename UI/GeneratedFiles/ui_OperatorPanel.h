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
#include <QtWidgets/QDial>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OperatorPanel
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *pitchDials_widget;
    QLabel *octave_label;
    QLabel *fine_label;
    QDial *note_dial;
    QLabel *note_label;
    QDial *fine_dial;
    QDial *octave_dial;

    void setupUi(QWidget *OperatorPanel)
    {
        if (OperatorPanel->objectName().isEmpty())
            OperatorPanel->setObjectName(QStringLiteral("OperatorPanel"));
        horizontalLayout = new QHBoxLayout(OperatorPanel);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pitchDials_widget = new QWidget(OperatorPanel);
        pitchDials_widget->setObjectName(QStringLiteral("pitchDials_widget"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pitchDials_widget->sizePolicy().hasHeightForWidth());
        pitchDials_widget->setSizePolicy(sizePolicy);
        pitchDials_widget->setMinimumSize(QSize(0, 180));
        pitchDials_widget->setMaximumSize(QSize(40, 1688888));
        octave_label = new QLabel(pitchDials_widget);
        octave_label->setObjectName(QStringLiteral("octave_label"));
        octave_label->setGeometry(QRect(0, 0, 40, 20));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(octave_label->sizePolicy().hasHeightForWidth());
        octave_label->setSizePolicy(sizePolicy1);
        octave_label->setAlignment(Qt::AlignCenter);
        fine_label = new QLabel(pitchDials_widget);
        fine_label->setObjectName(QStringLiteral("fine_label"));
        fine_label->setGeometry(QRect(0, 120, 40, 20));
        sizePolicy1.setHeightForWidth(fine_label->sizePolicy().hasHeightForWidth());
        fine_label->setSizePolicy(sizePolicy1);
        fine_label->setAlignment(Qt::AlignCenter);
        note_dial = new QDial(pitchDials_widget);
        note_dial->setObjectName(QStringLiteral("note_dial"));
        note_dial->setGeometry(QRect(0, 80, 40, 40));
        sizePolicy1.setHeightForWidth(note_dial->sizePolicy().hasHeightForWidth());
        note_dial->setSizePolicy(sizePolicy1);
        note_dial->setMinimum(-12);
        note_dial->setMaximum(12);
        note_label = new QLabel(pitchDials_widget);
        note_label->setObjectName(QStringLiteral("note_label"));
        note_label->setGeometry(QRect(0, 60, 40, 20));
        sizePolicy1.setHeightForWidth(note_label->sizePolicy().hasHeightForWidth());
        note_label->setSizePolicy(sizePolicy1);
        note_label->setAlignment(Qt::AlignCenter);
        fine_dial = new QDial(pitchDials_widget);
        fine_dial->setObjectName(QStringLiteral("fine_dial"));
        fine_dial->setGeometry(QRect(0, 140, 40, 40));
        sizePolicy1.setHeightForWidth(fine_dial->sizePolicy().hasHeightForWidth());
        fine_dial->setSizePolicy(sizePolicy1);
        fine_dial->setMinimum(-100);
        fine_dial->setMaximum(100);
        octave_dial = new QDial(pitchDials_widget);
        octave_dial->setObjectName(QStringLiteral("octave_dial"));
        octave_dial->setGeometry(QRect(0, 20, 40, 40));
        sizePolicy1.setHeightForWidth(octave_dial->sizePolicy().hasHeightForWidth());
        octave_dial->setSizePolicy(sizePolicy1);
        octave_dial->setMinimum(-4);
        octave_dial->setMaximum(4);

        horizontalLayout->addWidget(pitchDials_widget);


        retranslateUi(OperatorPanel);

        QMetaObject::connectSlotsByName(OperatorPanel);
    } // setupUi

    void retranslateUi(QWidget *OperatorPanel)
    {
        OperatorPanel->setWindowTitle(QApplication::translate("OperatorPanel", "OperatorPanel", nullptr));
        octave_label->setText(QApplication::translate("OperatorPanel", "Octave", nullptr));
        fine_label->setText(QApplication::translate("OperatorPanel", "Fine", nullptr));
        note_label->setText(QApplication::translate("OperatorPanel", "Note", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OperatorPanel: public Ui_OperatorPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPERATORPANEL_H
