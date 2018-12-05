#include "OperatorsListComponent.h"
#include "../Events/SynthEmilionEvent.h"
#include <sstream>

OperatorsListComponent::OperatorsListComponent(QWidget *parent)
	: SynthEmilionWidget(parent)
{
	ui.setupUi(this);
	listWidget = new QWidget;

	hLayout = new QHBoxLayout(listWidget);

	ui.scrollArea->setWidget(listWidget);
	ui.scrollArea->setWidgetResizable(true);

	for (int i = 0; i < NB_OPERATORS; i++)
	{
		std::unique_ptr<OperatorComponent>& newOp = addOperator();

		if (NB_ACTIVATED_OPERATORS > 0 && i < NB_ACTIVATED_OPERATORS)
		{
			newOp->activate();
		}
		else
		{
			newOp->deactivate();
		}
	}
}

OperatorsListComponent::~OperatorsListComponent()
{
}


std::unique_ptr<OperatorComponent>& OperatorsListComponent::addOperator()
{
	int left = 0;

	if (operators.size() > 0) {
		std::unique_ptr<OperatorComponent> &previousOp = operators.at(operators.size() - 1);
		left = previousOp->pos().x() + previousOp->width() + 5;
	}

	operators.emplace_back(new OperatorComponent(operators.size(), listWidget));
	std::unique_ptr<OperatorComponent> &newOp = operators.at(operators.size() - 1);

	newOp->move(left, 0);
	newOp->show();

	newOp->setEventsReceiver(this);

	return newOp;
}

void OperatorsListComponent::notifySynthEmilionMessage(std::shared_ptr<SQU::Comm::SynthEmilionMessage> message)
{
	if (message->component == SQU::Comm::ComponentType::Operator)
	{
		// Message on operator
		if (message->parameter == SQU::Comm::ParameterType::ComponentActivation)
		{
			// Operator activated / deactivated
			resetAllOperatorsData();
		}
	}

	SynthEmilionWidget::notifySynthEmilionMessage(message);
}


void OperatorsListComponent::resetAllOperatorsData()
{
	int curNb = 0;
	int left = 0;
	int height = 0;

	for (std::vector<std::unique_ptr<OperatorComponent>>::iterator it = operators.begin(); it != operators.end(); ++it, curNb++)
	{
		(*it)->move(left, 0);
		left = (*it)->pos().x() + (*it)->width() + 5;

		height = qMax((*it)->pos().y() + (*it)->height(), height);
	}

	listWidget->setFixedWidth(left);
	listWidget->setFixedHeight(height);

	ui.scrollArea->setFixedHeight(height + 2 + qApp->style()->pixelMetric(QStyle::PM_ScrollBarExtent));
}

