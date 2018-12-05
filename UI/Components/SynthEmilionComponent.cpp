#include "SynthEmilionComponent.h"

#include "../Events/ComponentFocusEvent.h"
#include "../Events/SynthEmilionEvent.h"


SynthEmilionComponent::SynthEmilionComponent(int number, SQU::Comm::ComponentType componentType, QWidget *parent)
	: SynthEmilionWidget(parent)
{
	this->componentType = componentType;
	this->number = number;
}

SynthEmilionComponent::~SynthEmilionComponent()
{
}

QString SynthEmilionComponent::getObjectTypeName()
{
	switch (componentType)
	{
	case SQU::Comm::ComponentType::Main:
		return "Main";
	case SQU::Comm::ComponentType::Operator:
		return "Operator";
	case SQU::Comm::ComponentType::Envelop:
		return "Envelop";
	case SQU::Comm::ComponentType::Filter:
		return "Filter";
	case SQU::Comm::ComponentType::LFO:
		return "LFO";
	default:
		return "Unknown";
	}
}

void SynthEmilionComponent::setActivationControl(QAbstractButton *button)
{
	this->activationButton = button;

	QString numString = QString::number(number + 1);
	QString objectName = getObjectTypeName() + " " + numString;
	activationButton->setText(objectName);

	refreshActiveState(button->isChecked());

	// TODO : Connect to button so param changed is handled
	connect(button, SIGNAL(stateChanged(int)), this, SLOT(activationChangedHandle(int)));
}

void SynthEmilionComponent::setDefaultBackColor(QString color)
{
	setStyleSheet("background-color:" + color + ";");
}

void SynthEmilionComponent::activate() {
	activationButton->setChecked(true);
}

void SynthEmilionComponent::deactivate() {
	activationButton->setChecked(false);
}


int SynthEmilionComponent::getNumber()
{
	return number;
}

void SynthEmilionComponent::activationChangedHandle(int state)
{
	bool active = (state == Qt::CheckState::Checked);

	refreshActiveState(active);

	sendParameterChangeEventBool(SQU::Comm::ParameterType::ComponentActivation, active);
}

void SynthEmilionComponent::refreshActiveState(bool active)
{
	this->number = number;

	int finalWidth = 0;
	int finalHeight = 0;

	foreach(QWidget *w, this->findChildren<QWidget *>())
	{
		if (w != activationButton)
		{
			if (active)
			{
				w->show();

				int right = w->x() + w->width();
				int bottom = w->y() + w->height();

				if (right > finalWidth)
				{
					finalWidth = right;
				}

				if (bottom > finalHeight)
				{
					finalHeight = bottom;
				}
			}
			else
			{
				w->hide();
			}
		}
	}

	QString nbString = QString::number(number + 1);

	if (active)
	{
		activationButton->setFixedWidth(91);
		activationButton->setText(getObjectTypeName() + " " + nbString);

		setFixedWidth(finalWidth);
		setFixedHeight(finalHeight);
	}
	else
	{
		activationButton->setFixedWidth(41);
		activationButton->setText(nbString);

		setFixedWidth(activationButton->width());
	}
}


void SynthEmilionComponent::afterSetupUi()
{
	installEventFilter(this);

	QList<QWidget*> widgets = this->findChildren<QWidget*>();

	foreach(QWidget *widget, widgets)
	{
		widget->installEventFilter(this);
	}
}

bool SynthEmilionComponent::eventFilter(QObject *obj, QEvent *event)
{
	if (event->type() == QEvent::MouseButtonPress)
	{
		ComponentFocusEvent *event = new ComponentFocusEvent(this);

		QApplication::postEvent(this, event);
	}
		
	return false;
}

QString SynthEmilionComponent::getObjectFullName()
{
	return getObjectTypeName() + " " + QString::number(number + 1);
}


/// /////////// ///
/// EVENTS POST ///
/// /////////// ///

void SynthEmilionComponent::sendParameterChangeEventBool(SQU::Comm::ParameterType parameterType, bool value)
{
	SynthEmilionEvent *event = new SynthEmilionEvent(componentType, getNumber(), parameterType);
	event->message->parameterValue.boolValue = value;

	QApplication::postEvent(this, event);
}

void SynthEmilionComponent::sendParameterChangeEventInt(SQU::Comm::ParameterType parameterType, int value)
{
	SynthEmilionEvent *event = new SynthEmilionEvent(componentType, getNumber(), parameterType);
	event->message->parameterValue.intValue = value;

	QApplication::postEvent(this, event);
}

void SynthEmilionComponent::sendParameterChangeEventDouble(SQU::Comm::ParameterType parameterType, double value)
{
	SynthEmilionEvent *event = new SynthEmilionEvent(componentType, getNumber(), parameterType);
	event->message->parameterValue.doubleValue = value;

	QApplication::postEvent(this, event);
}