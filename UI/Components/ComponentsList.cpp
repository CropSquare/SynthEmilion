#include "ComponentsList.h"
#include "OperatorComponent.h"

namespace SQU {
	namespace UI {
		ComponentsList::ComponentsList(QWidget *parent) : SynthEmilionWidget(parent)
		{
			ui.setupUi(this);

			componentsList_hLayout = new QHBoxLayout(ui.scrollAreaWidgetContents);
			componentsList_hLayout->setSpacing(0);
			componentsList_hLayout->setMargin(0);
		}

		ComponentsList::~ComponentsList()
		{
		}
	}
}