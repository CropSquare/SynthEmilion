#include "SynthEmilionEvent.h"

SynthEmilionEvent::SynthEmilionEvent(SQU::Comm::ComponentType componentType, int componentNumber, SQU::Comm::ParameterType parameter)
	: QEvent(SynthEmilionEvent::SynthEmilionEventType)
{
	message = std::shared_ptr<SQU::Comm::SynthEmilionMessage>(new SQU::Comm::SynthEmilionMessage());
	message->component = componentType;
	message->componentNumber = componentNumber;
	message->parameter = parameter;
}

SynthEmilionEvent::~SynthEmilionEvent()
{

}
