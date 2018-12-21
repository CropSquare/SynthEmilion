#include "UiViewer.h"


UiViewer::UiViewer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	mainWidget = new SQU::UI::MainWidget(this);
	mainWidget->show();

	setFixedWidth(mainWidget->width());
	setFixedHeight(mainWidget->height() + 200);

	installEventFilter(mainWidget);
}

bool UiViewer::eventFilter(QObject *obj, QEvent *ev)
{
	if (ev->type() == QEvent::Resize)
	{
		setFixedWidth(mainWidget->width());
		setFixedHeight(mainWidget->height());

		return true;
	}

	return QMainWindow::eventFilter(obj, ev);
}
