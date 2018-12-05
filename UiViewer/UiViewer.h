#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_UiViewer.h"

class UiViewer : public QMainWindow
{
	Q_OBJECT

public:
	UiViewer(QWidget *parent = Q_NULLPTR);

private:
	Ui::UiViewerClass ui;
};
