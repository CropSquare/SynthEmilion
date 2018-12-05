#include "MainWidget.h"

#include "../Events/SynthEmilionEvent.h"
#include "../Events/ComponentFocusEvent.h"

MainWidget::MainWidget(QWidget *parent)
	: SynthEmilionWidget(parent)
{
	ui.setupUi(this);

	opList = new OperatorsListComponent(this);
	opList->show();
	opList->setEventsReceiver(this);

	paramEventNb = 0;
	activeEventNb = 0;

	setFixedWidth(opList->x() + opList->width());
	setFixedHeight(ui.activeCompLabel->y() + 100);
}

MainWidget::~MainWidget()
{
}

void MainWidget::notifySynthEmilionMessage(std::shared_ptr<SQU::Comm::SynthEmilionMessage> message)
{
	paramEventNb++;
	ui.paramChangeLabel->setText("EV " + QString::number(paramEventNb) + " : Parameter " + QString::number(message->parameter) + " in component of type " + QString::number(message->component) + " with id " + QString::number(message->componentNumber) + " was changed");
}

void MainWidget::notifyComponentFocus(SynthEmilionComponent *component)
{
	if (currentlyFocusedComponent != component)
	{
		activeEventNb++;
		ui.activeCompLabel->setText("EV " + QString::number(activeEventNb) + " : Component focused: " + component->getObjectFullName());

		currentlyFocusedComponent = component;
	}
}