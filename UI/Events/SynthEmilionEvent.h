#pragma once

#include <QEvent>
#include "SynthEmilionMessage.h"
#include <memory>
#include "ui_global.h"

class SynthEmilionEvent : public QEvent
{
public:
	SynthEmilionEvent(SQU::Comm::ComponentType componentType, int componentNumber, SQU::Comm::ParameterType parameter);
	~SynthEmilionEvent();

	static const QEvent::Type SynthEmilionEventType = static_cast<QEvent::Type>(2000);

	std::shared_ptr<SQU::Comm::SynthEmilionMessage> message;
};
