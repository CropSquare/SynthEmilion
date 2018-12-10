#include "OperatorComponent.h"
#include "../Events/SynthEmilionEvent.h"

namespace SQU {
	namespace UI {
		OperatorComponent::OperatorComponent(int number, QWidget *parent)
			: SynthEmilionComponent(number, SQU::Comm::ComponentType::Operator, parent)
		{
			ui.setupUi(this);

			setObjectName(QString::number(number + 1));

			setActivationControl(ui.activation_button);

			connect(ui.pitch_dial, SIGNAL(valueChanged(int)), this, SLOT(pitchChangedHandle(int)));
			connect(ui.pan_dial, SIGNAL(valueChanged(int)), this, SLOT(panChangedHandle(int)));
			connect(ui.vol_dial, SIGNAL(valueChanged(int)), this, SLOT(volChangedHandle(int)));

			afterSetupUi();
		}

		OperatorComponent::~OperatorComponent()
		{
		}

		void OperatorComponent::pitchChangedHandle(int value)
		{
			sendParameterChangeEventInt(SQU::Comm::Pitch, value);
		}

		void OperatorComponent::panChangedHandle(int value)
		{
			sendParameterChangeEventInt(SQU::Comm::Pitch, value);
		}

		void OperatorComponent::volChangedHandle(int value)
		{
			sendParameterChangeEventInt(SQU::Comm::Pitch, value);
		}
	}
}