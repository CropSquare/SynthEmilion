/********************************************************************************
** Form generated from reading UI file 'MainComponent.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINCOMPONENT_H
#define UI_MAINCOMPONENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainComponent
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *title_label;
    QWidget *widget;
    QLabel *portamento_label;
    QDial *portamento_dial;
    QLabel *maxPolyphony_label;
    QSpinBox *maxPolyphony_spinBox;
    QLabel *mainVolume_label;
    QDial *mainVolume_dial;
    QLabel *monoLegato_label;
    QPushButton *monoLegato_button;
    QWidget *levelMeterContainer_widget;

    void setupUi(QWidget *MainComponent)
    {
        if (MainComponent->objectName().isEmpty())
            MainComponent->setObjectName(QStringLiteral("MainComponent"));
        MainComponent->resize(148, 563);
        verticalLayout = new QVBoxLayout(MainComponent);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        title_label = new QLabel(MainComponent);
        title_label->setObjectName(QStringLiteral("title_label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(title_label->sizePolicy().hasHeightForWidth());
        title_label->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(title_label);

        widget = new QWidget(MainComponent);
        widget->setObjectName(QStringLiteral("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(130, 130));
        widget->setMaximumSize(QSize(160000, 130));
        portamento_label = new QLabel(widget);
        portamento_label->setObjectName(QStringLiteral("portamento_label"));
        portamento_label->setGeometry(QRect(0, 30, 90, 30));
        portamento_dial = new QDial(widget);
        portamento_dial->setObjectName(QStringLiteral("portamento_dial"));
        portamento_dial->setGeometry(QRect(90, 30, 40, 30));
        maxPolyphony_label = new QLabel(widget);
        maxPolyphony_label->setObjectName(QStringLiteral("maxPolyphony_label"));
        maxPolyphony_label->setGeometry(QRect(0, 70, 90, 20));
        maxPolyphony_spinBox = new QSpinBox(widget);
        maxPolyphony_spinBox->setObjectName(QStringLiteral("maxPolyphony_spinBox"));
        maxPolyphony_spinBox->setGeometry(QRect(90, 70, 40, 20));
        maxPolyphony_spinBox->setMinimum(1);
        maxPolyphony_spinBox->setMaximum(96);
        mainVolume_label = new QLabel(widget);
        mainVolume_label->setObjectName(QStringLiteral("mainVolume_label"));
        mainVolume_label->setGeometry(QRect(0, 100, 90, 30));
        mainVolume_dial = new QDial(widget);
        mainVolume_dial->setObjectName(QStringLiteral("mainVolume_dial"));
        mainVolume_dial->setGeometry(QRect(90, 100, 40, 30));
        monoLegato_label = new QLabel(widget);
        monoLegato_label->setObjectName(QStringLiteral("monoLegato_label"));
        monoLegato_label->setGeometry(QRect(0, 0, 90, 30));
        monoLegato_button = new QPushButton(widget);
        monoLegato_button->setObjectName(QStringLiteral("monoLegato_button"));
        monoLegato_button->setGeometry(QRect(100, 5, 20, 20));

        verticalLayout->addWidget(widget);

        levelMeterContainer_widget = new QWidget(MainComponent);
        levelMeterContainer_widget->setObjectName(QStringLiteral("levelMeterContainer_widget"));
        levelMeterContainer_widget->setMinimumSize(QSize(0, 100));

        verticalLayout->addWidget(levelMeterContainer_widget);


        retranslateUi(MainComponent);

        QMetaObject::connectSlotsByName(MainComponent);
    } // setupUi

    void retranslateUi(QWidget *MainComponent)
    {
        MainComponent->setWindowTitle(QApplication::translate("MainComponent", "MainComponent", nullptr));
        title_label->setText(QApplication::translate("MainComponent", "Main", nullptr));
        title_label->setProperty("class", QVariant(QApplication::translate("MainComponent", "title", nullptr)));
        portamento_label->setText(QApplication::translate("MainComponent", "Portamento", nullptr));
        maxPolyphony_label->setText(QApplication::translate("MainComponent", "Max polyphony", nullptr));
        mainVolume_label->setText(QApplication::translate("MainComponent", "Main volume", nullptr));
        monoLegato_label->setText(QApplication::translate("MainComponent", "Mono legato", nullptr));
        monoLegato_button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainComponent: public Ui_MainComponent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINCOMPONENT_H
