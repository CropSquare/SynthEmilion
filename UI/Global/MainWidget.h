#pragma once

#include <QWidget>
#include "../GeneratedFiles/ui_MainWidget.h"
#include "../ComponentsLists/OperatorsListComponent.h"
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
			OperatorsListComponent* opList;

			int paramEventNb;
			int activeEventNb;

			SynthEmilionComponent* currentlyFocusedComponent;
		};
	}
}