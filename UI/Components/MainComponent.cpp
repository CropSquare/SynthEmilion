#include "MainComponent.h"

namespace SQU {
	namespace UI {
		MainComponent::MainComponent(QWidget *parent)
			: SynthEmilionWidget(parent)
		{
			ui.setupUi(this);

			levelMeterLayout = new QHBoxLayout(ui.levelMeterContainer_widget);
			
			leftLevelMeter = new LevelMeterWidget(nullptr);
			rightLevelMeter = new LevelMeterWidget(nullptr);
			levelMeterLayout->addWidget(leftLevelMeter);
			levelMeterLayout->addWidget(rightLevelMeter);
		}

		MainComponent::~MainComponent()
		{
		}
	}
}