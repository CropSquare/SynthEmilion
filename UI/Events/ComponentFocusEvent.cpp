#include "ComponentFocusEvent.h"

namespace SQU {
	namespace UI {
		ComponentFocusEvent::ComponentFocusEvent(SynthEmilionComponent *component)
			: QEvent(ComponentFocusEvent::ComponentFocusEventType)
		{
			this->component = component;
		}


		ComponentFocusEvent::~ComponentFocusEvent()
		{
		}
	}
}
