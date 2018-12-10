#include "ComponentPanel.h"

namespace SQU {
	namespace UI {
		ComponentPanel::ComponentPanel(SynthEmilionComponent *linkedComponent, QWidget *parent)
			: QWidget(parent)
		{
			this->linkedComponent = linkedComponent;
		}

		ComponentPanel::~ComponentPanel()
		{
		}
	}
}
