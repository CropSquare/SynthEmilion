#include "UiViewer.h"
#include "Global/MainWidget.h"

UiViewer::UiViewer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	MainWidget mainWidget = new MainWidget(this);
	mainWidget.show();

	setFixedWidth(mainWidget.width());
	setFixedHeight(mainWidget.height());
}