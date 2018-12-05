#include "ComponentFocusEvent.h"


ComponentFocusEvent::ComponentFocusEvent(SynthEmilionComponent *component)
	: QEvent(ComponentFocusEvent::ComponentFocusEventType)
{
	this->component = component;
}


ComponentFocusEvent::~ComponentFocusEvent()
{
}
