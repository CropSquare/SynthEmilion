#include "UiViewer.h"
#include "Global/MainWidget.h"

UiViewer::UiViewer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	SQU::UI::MainWidget mainWidget = new SQU::UI::MainWidget(this);
	mainWidget.show();

	setFixedWidth(mainWidget.width());
	setFixedHeight(mainWidget.height());
}
