#include "SynthEmilionComponent.h"
#include "../Events/ComponentFocusEvent.h"
#include "../Events/SynthEmilionEvent.h"

namespace SQU {
	namespace UI {
		SynthEmilionComponent::SynthEmilionComponent(int number, SQU::Comm::ComponentType componentType, QWidget *parent)
			: SynthEmilionWidget(parent)
		{
			this->componentType = componentType;
			this->number = number;
			this->setProperty("active", false);
			this->setProperty("alt", number % 2 == 1);

			setObjectName(QString::number(number + 1));
		}

		SynthEmilionComponent::~SynthEmilionComponent()
		{
		}

		QString SynthEmilionComponent::getObjectTypeName()
		{
			switch (componentType)
			{
			case SQU::Comm::ComponentType::Operator:
				return "Operator";
			case SQU::Comm::ComponentType::Envelope:
				return "Envelope";
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

			bool active = button->isChecked();

			this->setProperty("active", active);

			refreshActiveState(active);

			connect(button, SIGNAL(toggled(bool)), this, SLOT(activationChangedHandle(bool)));
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

		void SynthEmilionComponent::activationChangedHandle(bool state)
		{
			bool active = state;

			this->setProperty("active", active);

			refreshActiveState(active);

			this->style()->unpolish(this);
			this->style()->polish(this);

			sendParameterChangeEventBool(Comm::ParameterType::ComponentActivation, active);
		}
		
		void SynthEmilionComponent::refreshActiveState(bool active)
		{
			this->number = number;

			QString activationButtonText = active ? getObjectFullName() : QString::number(number + 1);

			activationButton->setText(activationButtonText);

			QFontMetrics metric(activationButton->font());
			activationButton->setFixedWidth(metric.horizontalAdvance(activationButtonText) + 20);

			int finalWidth = activationButton->width();
			int finalHeight = activationButton->height();

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

				w->style()->unpolish(w);
				w->style()->polish(w);
			}

			setFixedWidth(finalWidth);
			//setFixedHeight(finalHeight);
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

		void SynthEmilionComponent::sendParameterChangeEventBool(Comm::ParameterType parameterType, bool value)
		{
			SynthEmilionEvent *event = new SynthEmilionEvent(componentType, getNumber(), parameterType);
			event->message->parameterValue.boolValue = value;

			QApplication::postEvent(this, event);
		}

		void SynthEmilionComponent::sendParameterChangeEventInt(Comm::ParameterType parameterType, int value)
		{
			SynthEmilionEvent *event = new SynthEmilionEvent(componentType, getNumber(), parameterType);
			event->message->parameterValue.intValue = value;

			QApplication::postEvent(this, event);
		}

		void SynthEmilionComponent::sendParameterChangeEventDouble(Comm::ParameterType parameterType, double value)
		{
			SynthEmilionEvent *event = new SynthEmilionEvent(componentType, getNumber(), parameterType);
			event->message->parameterValue.doubleValue = value;

			QApplication::postEvent(this, event);
		}
	}
}