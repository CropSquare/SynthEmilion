#pragma once

#include <QWidget>
#include "../GeneratedFiles/ui_FilterComponent.h"
#include "../Global/SynthEmilionWidget.h"
#include "SynthEmilionComponent.h"
#include "SynthEmilionMessage.h"
#include "ui_global.h"

namespace SQU {
	namespace UI {
		class UI_EXPORT FilterComponent : public SynthEmilionComponent
		{
			Q_OBJECT

		public:
			FilterComponent(int number, QWidget *parent = Q_NULLPTR);
			~FilterComponent();

		private:
			Ui::FilterComponent ui;
		};
	}
}