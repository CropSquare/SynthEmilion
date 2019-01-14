/********************************************************************************
** Form generated from reading UI file 'CurveEditorWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURVEEDITORWIDGET_H
#define UI_CURVEEDITORWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CurveEditorWidget
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *operatorCurve_scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    QLabel *wavePreset_label;
    QComboBox *wavePreset_comboBox;
    QLabel *zoom_label;
    QPushButton *zoomMinus_pushButton;
    QPushButton *zoomPlus_pushButton;
    QLabel *currentPoint_label;
    QLineEdit *currentPointFunction_lineEdit;
    QLabel *currentPointLength_label;
    QLineEdit *currentPointLength_lineEdit;
    QPushButton *currentPointDataValidation_pushButton;
    QPushButton *deleteCurrentPoint_pushButton;
    QPushButton *addPoint_pushButton;

    void setupUi(QWidget *CurveEditorWidget)
    {
        if (CurveEditorWidget->objectName().isEmpty())
            CurveEditorWidget->setObjectName(QStringLiteral("CurveEditorWidget"));
        CurveEditorWidget->resize(870, 393);
        verticalLayout = new QVBoxLayout(CurveEditorWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        operatorCurve_scrollArea = new QScrollArea(CurveEditorWidget);
        operatorCurve_scrollArea->setObjectName(QStringLiteral("operatorCurve_scrollArea"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(operatorCurve_scrollArea->sizePolicy().hasHeightForWidth());
        operatorCurve_scrollArea->setSizePolicy(sizePolicy);
        operatorCurve_scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 868, 366));
        operatorCurve_scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(operatorCurve_scrollArea);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        wavePreset_label = new QLabel(CurveEditorWidget);
        wavePreset_label->setObjectName(QStringLiteral("wavePreset_label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(wavePreset_label->sizePolicy().hasHeightForWidth());
        wavePreset_label->setSizePolicy(sizePolicy1);
        wavePreset_label->setMaximumSize(QSize(16777215, 20));

        horizontalLayout->addWidget(wavePreset_label);

        wavePreset_comboBox = new QComboBox(CurveEditorWidget);
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

        horizontalLayout->addWidget(wavePreset_comboBox);

        zoom_label = new QLabel(CurveEditorWidget);
        zoom_label->setObjectName(QStringLiteral("zoom_label"));
        sizePolicy1.setHeightForWidth(zoom_label->sizePolicy().hasHeightForWidth());
        zoom_label->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(zoom_label);

        zoomMinus_pushButton = new QPushButton(CurveEditorWidget);
        zoomMinus_pushButton->setObjectName(QStringLiteral("zoomMinus_pushButton"));
        sizePolicy1.setHeightForWidth(zoomMinus_pushButton->sizePolicy().hasHeightForWidth());
        zoomMinus_pushButton->setSizePolicy(sizePolicy1);
        zoomMinus_pushButton->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(zoomMinus_pushButton);

        zoomPlus_pushButton = new QPushButton(CurveEditorWidget);
        zoomPlus_pushButton->setObjectName(QStringLiteral("zoomPlus_pushButton"));
        sizePolicy1.setHeightForWidth(zoomPlus_pushButton->sizePolicy().hasHeightForWidth());
        zoomPlus_pushButton->setSizePolicy(sizePolicy1);
        zoomPlus_pushButton->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(zoomPlus_pushButton);

        currentPoint_label = new QLabel(CurveEditorWidget);
        currentPoint_label->setObjectName(QStringLiteral("currentPoint_label"));
        sizePolicy1.setHeightForWidth(currentPoint_label->sizePolicy().hasHeightForWidth());
        currentPoint_label->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(currentPoint_label);

        currentPointFunction_lineEdit = new QLineEdit(CurveEditorWidget);
        currentPointFunction_lineEdit->setObjectName(QStringLiteral("currentPointFunction_lineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(currentPointFunction_lineEdit->sizePolicy().hasHeightForWidth());
        currentPointFunction_lineEdit->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(currentPointFunction_lineEdit);

        currentPointLength_label = new QLabel(CurveEditorWidget);
        currentPointLength_label->setObjectName(QStringLiteral("currentPointLength_label"));
        sizePolicy1.setHeightForWidth(currentPointLength_label->sizePolicy().hasHeightForWidth());
        currentPointLength_label->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(currentPointLength_label);

        currentPointLength_lineEdit = new QLineEdit(CurveEditorWidget);
        currentPointLength_lineEdit->setObjectName(QStringLiteral("currentPointLength_lineEdit"));
        sizePolicy1.setHeightForWidth(currentPointLength_lineEdit->sizePolicy().hasHeightForWidth());
        currentPointLength_lineEdit->setSizePolicy(sizePolicy1);
        currentPointLength_lineEdit->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(currentPointLength_lineEdit);

        currentPointDataValidation_pushButton = new QPushButton(CurveEditorWidget);
        currentPointDataValidation_pushButton->setObjectName(QStringLiteral("currentPointDataValidation_pushButton"));
        sizePolicy1.setHeightForWidth(currentPointDataValidation_pushButton->sizePolicy().hasHeightForWidth());
        currentPointDataValidation_pushButton->setSizePolicy(sizePolicy1);
        currentPointDataValidation_pushButton->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(currentPointDataValidation_pushButton);

        deleteCurrentPoint_pushButton = new QPushButton(CurveEditorWidget);
        deleteCurrentPoint_pushButton->setObjectName(QStringLiteral("deleteCurrentPoint_pushButton"));
        sizePolicy1.setHeightForWidth(deleteCurrentPoint_pushButton->sizePolicy().hasHeightForWidth());
        deleteCurrentPoint_pushButton->setSizePolicy(sizePolicy1);
        deleteCurrentPoint_pushButton->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(deleteCurrentPoint_pushButton);

        addPoint_pushButton = new QPushButton(CurveEditorWidget);
        addPoint_pushButton->setObjectName(QStringLiteral("addPoint_pushButton"));
        sizePolicy1.setHeightForWidth(addPoint_pushButton->sizePolicy().hasHeightForWidth());
        addPoint_pushButton->setSizePolicy(sizePolicy1);
        addPoint_pushButton->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(addPoint_pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(CurveEditorWidget);

        QMetaObject::connectSlotsByName(CurveEditorWidget);
    } // setupUi

    void retranslateUi(QWidget *CurveEditorWidget)
    {
        CurveEditorWidget->setWindowTitle(QApplication::translate("CurveEditorWidget", "CurveEditorWidget", nullptr));
        wavePreset_label->setText(QApplication::translate("CurveEditorWidget", "Wave preset", nullptr));
        wavePreset_comboBox->setItemText(0, QApplication::translate("CurveEditorWidget", "Sine", nullptr));
        wavePreset_comboBox->setItemText(1, QApplication::translate("CurveEditorWidget", "Saw", nullptr));
        wavePreset_comboBox->setItemText(2, QApplication::translate("CurveEditorWidget", "Square", nullptr));
        wavePreset_comboBox->setItemText(3, QApplication::translate("CurveEditorWidget", "Pulse", nullptr));
        wavePreset_comboBox->setItemText(4, QApplication::translate("CurveEditorWidget", "White noise", nullptr));
        wavePreset_comboBox->setItemText(5, QApplication::translate("CurveEditorWidget", "Pink noise", nullptr));

        zoom_label->setText(QApplication::translate("CurveEditorWidget", "Zoom", nullptr));
        zoomMinus_pushButton->setText(QApplication::translate("CurveEditorWidget", "-", nullptr));
        zoomPlus_pushButton->setText(QApplication::translate("CurveEditorWidget", "+", nullptr));
        currentPoint_label->setText(QApplication::translate("CurveEditorWidget", "Point 1", nullptr));
        currentPointLength_label->setText(QApplication::translate("CurveEditorWidget", "Length", nullptr));
        currentPointDataValidation_pushButton->setText(QApplication::translate("CurveEditorWidget", "V", nullptr));
        deleteCurrentPoint_pushButton->setText(QApplication::translate("CurveEditorWidget", "X", nullptr));
        addPoint_pushButton->setText(QApplication::translate("CurveEditorWidget", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CurveEditorWidget: public Ui_CurveEditorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURVEEDITORWIDGET_H
