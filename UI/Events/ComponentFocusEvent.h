#pragma once

#include <QEvent>
#include "../Components/SynthEmilionComponent.h"
#include "ui_global.h"

namespace SQU {
	namespace UI {
		class ComponentFocusEvent : public QEvent
		{
		public:
			ComponentFocusEvent(SynthEmilionComponent *component);
			~ComponentFocusEvent();

			static const QEvent::Type ComponentFocusEventType = static_cast<QEvent::Type>(2001);

			SynthEmilionComponent *component;
		};
	}
}
