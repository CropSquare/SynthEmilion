#pragma once
#include <QtWidgets/QApplication>
#include <QtWidgets/QAbstractButton>
#include "../Global/SynthEmilionWidget.h"
#include "SynthEmilionMessage.h"
#include "ui_global.h"

namespace SQU {
	namespace UI {
		class SynthEmilionComponent : public SynthEmilionWidget
		{
			Q_OBJECT

		public:
			SynthEmilionComponent(int number, SQU::Comm::ComponentType componentType, QWidget *parent);
			~SynthEmilionComponent();

			int getNumber();

			void activate();
			void deactivate();


			QString getObjectFullName();

		protected:
			void setActivationControl(QAbstractButton *button);
			Comm::ComponentType componentType;
			void sendParameterChangeEventBool(Comm::ParameterType parameterType, bool value);
			void sendParameterChangeEventInt(Comm::ParameterType parameterType, int value);
			void sendParameterChangeEventDouble(Comm::ParameterType parameterType, double value);

			void afterSetupUi();

			private slots:
			void activationChangedHandle(bool state);
			bool eventFilter(QObject *obj, QEvent *event);

		private:
			QString getObjectTypeName();
			QAbstractButton *activationButton;
			int number;
			void refreshActiveState(bool active);
		};
	}
}
