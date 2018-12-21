#include "FilterComponent.h"


namespace SQU {
	namespace UI {
		FilterComponent::FilterComponent(int number, QWidget *parent)
			: SynthEmilionComponent(number, SQU::Comm::ComponentType::Filter, parent)
		{
			ui.setupUi(this);

			setActivationControl(ui.activation_button);

			afterSetupUi();
		}

		FilterComponent::~FilterComponent()
		{
		}
	}
}
