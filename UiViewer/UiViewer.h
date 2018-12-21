#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_UiViewer.h"
#include "Global/MainWidget.h"

class UiViewer : public QMainWindow
{
	Q_OBJECT

public:
	UiViewer(QWidget *parent = Q_NULLPTR);

	bool eventFilter(QObject *, QEvent *) override;
private:
	Ui::UiViewerClass ui;
	SQU::UI::MainWidget* mainWidget;
};
