#include "LfoComponent.h"


namespace SQU {
	namespace UI {
		LfoComponent::LfoComponent(int number, QWidget *parent)
			: SynthEmilionComponent(number, SQU::Comm::ComponentType::LFO, parent)
		{
			ui.setupUi(this);

			setActivationControl(ui.activation_button);

			afterSetupUi();
		}

		LfoComponent::~LfoComponent()
		{
		}
	}
}