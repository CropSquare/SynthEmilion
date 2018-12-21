#pragma once

#include <QWidget>
#include "../GeneratedFiles/ui_MainWidget.h"
#include "../Components/SpecializedComponentsList.h"
#include "../Components/MainComponent.h"
#include "SynthEmilionWidget.h"
#include "SynthEmilionMessage.h"
#include "ui_global.h"

namespace SQU {
	namespace UI {
		class UI_EXPORT MainWidget : public SynthEmilionWidget
		{
			Q_OBJECT

		public:
			MainWidget(QWidget *parent = Q_NULLPTR);
			~MainWidget();

			void notifySynthEmilionMessage(std::shared_ptr<Comm::SynthEmilionMessage> message) override;
			void notifyComponentFocus(SynthEmilionComponent *component) override;

		private slots:
			void reloadQss();

		private:
			Ui::MainWidget ui;
			OperatorsList* opList;
			EnvelopesList* envList;
			FiltersList* fltList;
			LfosList* lfosList;
			MainComponent* mainComponent;

			int paramEventNb;
			int activeEventNb;

			SynthEmilionComponent* currentlyFocusedComponent = nullptr;
		};
	}
}