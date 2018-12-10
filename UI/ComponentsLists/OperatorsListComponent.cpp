#include "OperatorsListComponent.h"
#include "../Events/SynthEmilionEvent.h"
#include <sstream>

namespace SQU {
	namespace UI {
		OperatorsListComponent::OperatorsListComponent(QWidget *parent)
			: SynthEmilionWidget(parent)
		{
			ui.setupUi(this);

			hLayout = new QHBoxLayout(ui.scrollArea->widget());

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
			operators.emplace_back(new OperatorComponent(operators.size(), nullptr));
			std::unique_ptr<OperatorComponent> &newOp = operators.at(operators.size() - 1);

			newOp->setEventsReceiver(this);

			hLayout->addWidget(newOp.get());
			
			return newOp;
		}
	}
}