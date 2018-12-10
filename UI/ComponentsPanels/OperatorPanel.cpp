#include "OperatorPanel.h"

namespace SQU {
	namespace UI {
		OperatorPanel::OperatorPanel(SynthEmilionComponent *linkedOperatorComponent, QWidget *parent)
			: ComponentPanel(linkedOperatorComponent, parent)
		{
			ui.setupUi(this);
		}

		OperatorPanel::~OperatorPanel()
		{
		}
	}
}