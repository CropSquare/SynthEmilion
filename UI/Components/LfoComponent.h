#pragma once

#include <QWidget>
#include "../GeneratedFiles/ui_LfoComponent.h"
#include "../Global/SynthEmilionWidget.h"
#include "SynthEmilionComponent.h"
#include "SynthEmilionMessage.h"
#include "ui_global.h"

namespace SQU {
	namespace UI {
		class UI_EXPORT LfoComponent : public SynthEmilionComponent
		{
			Q_OBJECT

		public:
			LfoComponent(int number, QWidget *parent = Q_NULLPTR);
			~LfoComponent();

		private:
			Ui::LfoComponent ui;
		};
	}
}