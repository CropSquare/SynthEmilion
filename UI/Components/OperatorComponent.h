#pragma once

#include <QWidget>
#include "../GeneratedFiles/ui_OperatorComponent.h"
#include "../Global/SynthEmilionWidget.h"
#include "SynthEmilionComponent.h"
#include "SynthEmilionMessage.h"
#include "ui_global.h"

namespace SQU {
	namespace UI {
		class OperatorComponent : public SynthEmilionComponent
		{
			Q_OBJECT

		public:
			OperatorComponent(int number, QWidget *parent = Q_NULLPTR);
			~OperatorComponent();

		private slots:
			void pitchChangedHandle(int value);
			void panChangedHandle(int value);
			void volChangedHandle(int value);

		private:

			Ui::OperatorComponent ui;
		};
	}
}
