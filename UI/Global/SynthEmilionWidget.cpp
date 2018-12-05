#include "SynthEmilionWidget.h"
#include "../Events/ComponentFocusEvent.h"

SynthEmilionWidget::SynthEmilionWidget(QWidget *parent)
	: QWidget(parent)
{
}

SynthEmilionWidget::~SynthEmilionWidget()
{
}

void SynthEmilionWidget::setEventsReceiver(SynthEmilionWidget *widget)
{
	eventsReceiver = widget;
}

void SynthEmilionWidget::paintEvent(QPaintEvent* event)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

	QWidget::paintEvent(event);
}

bool SynthEmilionWidget::event(QEvent *event)
{
	if (event->type() == SynthEmilionEvent::SynthEmilionEventType)		
	{
		SynthEmilionEvent *smEvent = reinterpret_cast<SynthEmilionEvent *>(event);

		dispatchSynthEmilionMessage(smEvent->message);
	}
	else if (event->type() == ComponentFocusEvent::ComponentFocusEventType)
	{
		ComponentFocusEvent *cfEvent = reinterpret_cast<ComponentFocusEvent *>(event);

		dispatchComponentFocus(cfEvent->component);
	}

	return QWidget::event(event);
}

void SynthEmilionWidget::notifySynthEmilionMessage(std::shared_ptr<SQU::Comm::SynthEmilionMessage> message)
{
	dispatchSynthEmilionMessage(message);
}

void SynthEmilionWidget::notifyComponentFocus(SynthEmilionComponent *component)
{
	dispatchComponentFocus(component);
}

void SynthEmilionWidget::dispatchSynthEmilionMessage(std::shared_ptr<SQU::Comm::SynthEmilionMessage> message)
{
	if (eventsReceiver != nullptr)
	{
		eventsReceiver->notifySynthEmilionMessage(message);
	}
}

void SynthEmilionWidget::dispatchComponentFocus(SynthEmilionComponent *component)
{
	if (eventsReceiver != nullptr)
	{
		eventsReceiver->notifyComponentFocus(component);
	}
}