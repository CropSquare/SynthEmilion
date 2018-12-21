#include "EnvelopeComponent.h"
#include "../Events/SynthEmilionEvent.h"

namespace SQU {
	namespace UI {
		EnvelopeComponent::EnvelopeComponent(int number, QWidget *parent)
			: SynthEmilionComponent(number, SQU::Comm::ComponentType::Envelope, parent)
		{
			ui.setupUi(this);

			setActivationControl(ui.activation_button);

			connect(ui.attack_slider, SIGNAL(valueChanged(int)), this, SLOT(attackChangedHandle(int)));
			connect(ui.attackBend_dial, SIGNAL(valueChanged(int)), this, SLOT(attackBendChangedHandle(int)));

			connect(ui.decay_slider, SIGNAL(valueChanged(int)), this, SLOT(decayChangedHandle(int)));
			connect(ui.decayBend_dial, SIGNAL(valueChanged(int)), this, SLOT(decayBendChangedHandle(int)));

			connect(ui.sustain_slider, SIGNAL(valueChanged(int)), this, SLOT(sustainChangedHandle(int)));

			connect(ui.release_slider, SIGNAL(valueChanged(int)), this, SLOT(releaseChangedHandle(int)));
			connect(ui.releaseBend_dial, SIGNAL(valueChanged(int)), this, SLOT(releaseBendChangedHandle(int)));

			afterSetupUi();
		}

		EnvelopeComponent::~EnvelopeComponent()
		{
		}

		void EnvelopeComponent::attackChangedHandle(int value)
		{
			sendParameterChangeEventInt(SQU::Comm::Attack, value);
		}

		void EnvelopeComponent::attackBendChangedHandle(int value)
		{
			sendParameterChangeEventInt(SQU::Comm::AttackBend, value);
		}

		void EnvelopeComponent::decayChangedHandle(int value)
		{
			sendParameterChangeEventInt(SQU::Comm::Decay, value);
		}

		void EnvelopeComponent::decayBendChangedHandle(int value)
		{
			sendParameterChangeEventInt(SQU::Comm::DecayBend, value);
		}

		void EnvelopeComponent::sustainChangedHandle(int value)
		{
			sendParameterChangeEventInt(SQU::Comm::Sustain, value);
		}

		void EnvelopeComponent::releaseChangedHandle(int value)
		{
			sendParameterChangeEventInt(SQU::Comm::Release, value);
		}

		void EnvelopeComponent::releaseBendChangedHandle(int value)
		{
			sendParameterChangeEventInt(SQU::Comm::ReleaseBend, value);
		}
	}
}