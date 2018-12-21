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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OperatorPanel
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QLabel *octave_label;
    QLabel *fine_label;
    QDial *note_dial;
    QLabel *note_label;
    QDial *fine_dial;
    QDial *octave_dial;
    QVBoxLayout *verticalLayout;
    QScrollArea *operatorCurve_scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    QLabel *wavePreset_label;
    QComboBox *wavePreset_comboBox;
    QLabel *currentPoint_label;
    QLineEdit *currentPointFunction_lineEdit;
    QPushButton *currentPointFunctionValidation_pushButton;

    void setupUi(QWidget *OperatorPanel)
    {
        if (OperatorPanel->objectName().isEmpty())
            OperatorPanel->setObjectName(QStringLiteral("OperatorPanel"));
        OperatorPanel->resize(847, 182);
        gridLayout = new QGridLayout(OperatorPanel);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget = new QWidget(OperatorPanel);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(0, 180));
        widget->setMaximumSize(QSize(40, 1688888));
        octave_label = new QLabel(widget);
        octave_label->setObjectName(QStringLiteral("octave_label"));
        octave_label->setGeometry(QRect(0, 0, 40, 20));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(octave_label->sizePolicy().hasHeightForWidth());
        octave_label->setSizePolicy(sizePolicy1);
        octave_label->setAlignment(Qt::AlignCenter);
        fine_label = new QLabel(widget);
        fine_label->setObjectName(QStringLiteral("fine_label"));
        fine_label->setGeometry(QRect(0, 120, 40, 20));
        sizePolicy1.setHeightForWidth(fine_label->sizePolicy().hasHeightForWidth());
        fine_label->setSizePolicy(sizePolicy1);
        fine_label->setAlignment(Qt::AlignCenter);
        note_dial = new QDial(widget);
        note_dial->setObjectName(QStringLiteral("note_dial"));
        note_dial->setGeometry(QRect(0, 80, 40, 40));
        sizePolicy1.setHeightForWidth(note_dial->sizePolicy().hasHeightForWidth());
        note_dial->setSizePolicy(sizePolicy1);
        note_dial->setMinimum(-12);
        note_dial->setMaximum(12);
        note_label = new QLabel(widget);
        note_label->setObjectName(QStringLiteral("note_label"));
        note_label->setGeometry(QRect(0, 60, 40, 20));
        sizePolicy1.setHeightForWidth(note_label->sizePolicy().hasHeightForWidth());
        note_label->setSizePolicy(sizePolicy1);
        note_label->setAlignment(Qt::AlignCenter);
        fine_dial = new QDial(widget);
        fine_dial->setObjectName(QStringLiteral("fine_dial"));
        fine_dial->setGeometry(QRect(0, 140, 40, 40));
        sizePolicy1.setHeightForWidth(fine_dial->sizePolicy().hasHeightForWidth());
        fine_dial->setSizePolicy(sizePolicy1);
        fine_dial->setMinimum(-100);
        fine_dial->setMaximum(100);
        octave_dial = new QDial(widget);
        octave_dial->setObjectName(QStringLiteral("octave_dial"));
        octave_dial->setGeometry(QRect(0, 20, 40, 40));
        sizePolicy1.setHeightForWidth(octave_dial->sizePolicy().hasHeightForWidth());
        octave_dial->setSizePolicy(sizePolicy1);
        octave_dial->setMinimum(-4);
        octave_dial->setMaximum(4);

        horizontalLayout->addWidget(widget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        operatorCurve_scrollArea = new QScrollArea(OperatorPanel);
        operatorCurve_scrollArea->setObjectName(QStringLiteral("operatorCurve_scrollArea"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(operatorCurve_scrollArea->sizePolicy().hasHeightForWidth());
        operatorCurve_scrollArea->setSizePolicy(sizePolicy2);
        operatorCurve_scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 796, 145));
        operatorCurve_scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(operatorCurve_scrollArea);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        wavePreset_label = new QLabel(OperatorPanel);
        wavePreset_label->setObjectName(QStringLiteral("wavePreset_label"));
        sizePolicy1.setHeightForWidth(wavePreset_label->sizePolicy().hasHeightForWidth());
        wavePreset_label->setSizePolicy(sizePolicy1);
        wavePreset_label->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_2->addWidget(wavePreset_label);

        wavePreset_comboBox = new QComboBox(OperatorPanel);
        wavePreset_comboBox->addItem(QString());
        wavePreset_comboBox->addItem(QString());
        wavePreset_comboBox->addItem(QString());
        wavePreset_comboBox->addItem(QString());
        wavePreset_comboBox->addItem(QString());
        wavePreset_comboBox->addItem(QString());
        wavePreset_comboBox->setObjectName(QStringLiteral("wavePreset_comboBox"));
        sizePolicy1.setHeightForWidth(wavePreset_comboBox->sizePolicy().hasHeightForWidth());
        wavePreset_comboBox->setSizePolicy(sizePolicy1);
        wavePreset_comboBox->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_2->addWidget(wavePreset_comboBox);

        currentPoint_label = new QLabel(OperatorPanel);
        currentPoint_label->setObjectName(QStringLiteral("currentPoint_label"));
        sizePolicy1.setHeightForWidth(currentPoint_label->sizePolicy().hasHeightForWidth());
        currentPoint_label->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(currentPoint_label);

        currentPointFunction_lineEdit = new QLineEdit(OperatorPanel);
        currentPointFunction_lineEdit->setObjectName(QStringLiteral("currentPointFunction_lineEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(currentPointFunction_lineEdit->sizePolicy().hasHeightForWidth());
        currentPointFunction_lineEdit->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(currentPointFunction_lineEdit);

        currentPointFunctionValidation_pushButton = new QPushButton(OperatorPanel);
        currentPointFunctionValidation_pushButton->setObjectName(QStringLiteral("currentPointFunctionValidation_pushButton"));
        sizePolicy1.setHeightForWidth(currentPointFunctionValidation_pushButton->sizePolicy().hasHeightForWidth());
        currentPointFunctionValidation_pushButton->setSizePolicy(sizePolicy1);
        currentPointFunctionValidation_pushButton->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_2->addWidget(currentPointFunctionValidation_pushButton);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(OperatorPanel);

        QMetaObject::connectSlotsByName(OperatorPanel);
    } // setupUi

    void retranslateUi(QWidget *OperatorPanel)
    {
        OperatorPanel->setWindowTitle(QApplication::translate("OperatorPanel", "OperatorPanel", nullptr));
        octave_label->setText(QApplication::translate("OperatorPanel", "Octave", nullptr));
        fine_label->setText(QApplication::translate("OperatorPanel", "Fine", nullptr));
        note_label->setText(QApplication::translate("OperatorPanel", "Note", nullptr));
        wavePreset_label->setText(QApplication::translate("OperatorPanel", "Wave preset", nullptr));
        wavePreset_comboBox->setItemText(0, QApplication::translate("OperatorPanel", "Sine", nullptr));
        wavePreset_comboBox->setItemText(1, QApplication::translate("OperatorPanel", "Saw", nullptr));
        wavePreset_comboBox->setItemText(2, QApplication::translate("OperatorPanel", "Square", nullptr));
        wavePreset_comboBox->setItemText(3, QApplication::translate("OperatorPanel", "Pulse", nullptr));
        wavePreset_comboBox->setItemText(4, QApplication::translate("OperatorPanel", "White noise", nullptr));
        wavePreset_comboBox->setItemText(5, QApplication::translate("OperatorPanel", "Pink noise", nullptr));

        currentPoint_label->setText(QApplication::translate("OperatorPanel", "Point 1", nullptr));
        currentPointFunctionValidation_pushButton->setText(QApplication::translate("OperatorPanel", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OperatorPanel: public Ui_OperatorPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPERATORPANEL_H
