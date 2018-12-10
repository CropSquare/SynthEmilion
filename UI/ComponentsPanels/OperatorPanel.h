#pragma once

#include <QWidget>
#include "ui_OperatorPanel.h"
#include "ComponentPanel.h"

class SynthEmilionComponent;

namespace SQU {
	namespace UI {

		class OperatorPanel : public ComponentPanel
		{
			Q_OBJECT

		public:
			OperatorPanel(SynthEmilionComponent *linkedOperatorComponent, QWidget *parent = Q_NULLPTR);
			~OperatorPanel();

		private:
			Ui::OperatorPanel ui;
		};
	}
}