#pragma once

#include <QWidget>
#include "../GeneratedFiles/ui_MainComponent.h"
#include "../AudioUtils/LevelMeterWidget.h"
#include "../Global/SynthEmilionWidget.h"
#include "SynthEmilionMessage.h"
#include "ui_global.h"

namespace SQU {
	namespace UI {
		class UI_EXPORT MainComponent : public SynthEmilionWidget
		{
			Q_OBJECT

		public:
			MainComponent(QWidget *parent = Q_NULLPTR);
			~MainComponent();

		private:
			Ui::MainComponent ui;
			QHBoxLayout* levelMeterLayout;
			LevelMeterWidget* leftLevelMeter;
			LevelMeterWidget* rightLevelMeter;
		};
	}
}