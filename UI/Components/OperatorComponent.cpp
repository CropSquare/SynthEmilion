#include "OperatorComponent.h"
#include "../Events/SynthEmilionEvent.h"

namespace SQU {
	namespace UI {
		OperatorComponent::OperatorComponent(int number, QWidget *parent)
			: SynthEmilionComponent(number, SQU::Comm::ComponentType::Operator, parent)
		{
			ui.setupUi(this);

			associatedOperatorPanel = new OperatorPanel(this);
			associatedPanel = associatedOperatorPanel;
			
			setActivationControl(ui.activation_button);

			connect(ui.pitch_dial, SIGNAL(valueChanged(int)), this, SLOT(pitchChangedHandle(int)));
			connect(ui.pan_dial, SIGNAL(valueChanged(int)), this, SLOT(panChangedHandle(int)));
			connect(ui.vol_dial, SIGNAL(valueChanged(int)), this, SLOT(volChangedHandle(int)));

			afterSetupUi();
		}

		OperatorComponent::~OperatorComponent()
		{
		}

		void OperatorComponent::notifyPitch(int pitch)
		{
			ui.pitch_dial->setValue(pitch);
		}

		void OperatorComponent::pitchChangedHandle(int value)
		{
			sendParameterChangeEventInt(SQU::Comm::Pitch, value);

			// Notify operator panel
			associatedOperatorPanel->notifyPitch(value);
		}

		void OperatorComponent::panChangedHandle(int value)
		{
			sendParameterChangeEventInt(SQU::Comm::Pan, value);
		}

		void OperatorComponent::volChangedHandle(int value)
		{
			sendParameterChangeEventInt(SQU::Comm::Volume, value);
		}
	}
}