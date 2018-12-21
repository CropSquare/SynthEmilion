#pragma once

#include <QWidget>
#include "../GeneratedFiles/ui_OperatorComponent.h"
#include "../Global/SynthEmilionWidget.h"
#include "SynthEmilionComponent.h"
#include "SynthEmilionMessage.h"
#include "../ComponentsPanels/OperatorPanel.h"
#include "ui_global.h"

namespace SQU {
	namespace UI {
		class UI_EXPORT OperatorComponent : public SynthEmilionComponent
		{
			Q_OBJECT

		public:
			OperatorComponent(int number, QWidget *parent = Q_NULLPTR);
			~OperatorComponent();

			void notifyPitch(int pitch);

		private slots:
			void pitchChangedHandle(int value);
			void panChangedHandle(int value);
			void volChangedHandle(int value);

		private:
			OperatorPanel* associatedOperatorPanel;
			Ui::OperatorComponent ui;
		};
	}
}
