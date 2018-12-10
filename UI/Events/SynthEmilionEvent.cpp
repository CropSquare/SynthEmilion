#include "SynthEmilionEvent.h"

namespace SQU {
	namespace UI {
		SynthEmilionEvent::SynthEmilionEvent(Comm::ComponentType componentType, int componentNumber, Comm::ParameterType parameter)
			: QEvent(SynthEmilionEvent::SynthEmilionEventType)
		{
			message = std::shared_ptr<Comm::SynthEmilionMessage>(new Comm::SynthEmilionMessage());
			message->component = componentType;
			message->componentNumber = componentNumber;
			message->parameter = parameter;
		}

		SynthEmilionEvent::~SynthEmilionEvent()
		{
		}
	}
}
