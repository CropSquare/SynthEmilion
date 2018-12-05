#pragma once

#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include "ui_global.h"
#include "SynthEmilionMessage.h"
#include "../Events/SynthEmilionEvent.h"

class SynthEmilionComponent;

class UI_EXPORT  SynthEmilionWidget : public QWidget
{
	Q_OBJECT

public:
	SynthEmilionWidget(QWidget *parent);
	~SynthEmilionWidget();

	void setEventsReceiver(SynthEmilionWidget *widget);
	void paintEvent(QPaintEvent* event);
	
	bool event(QEvent *) override;

	virtual void notifySynthEmilionMessage(std::shared_ptr<SQU::Comm::SynthEmilionMessage> message);
	virtual void notifyComponentFocus(SynthEmilionComponent *component);

private:
	void dispatchSynthEmilionMessage(std::shared_ptr<SQU::Comm::SynthEmilionMessage> message);
	void dispatchComponentFocus(SynthEmilionComponent *component);
	SynthEmilionWidget* eventsReceiver;
	
};
