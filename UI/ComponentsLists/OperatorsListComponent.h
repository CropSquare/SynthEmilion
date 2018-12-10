#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <memory>
#include "../GeneratedFiles/ui_OperatorsListComponent.h"
#include "../Components/OperatorComponent.h"
#include "../Global/SynthEmilionWidget.h"
#include "ui_global.h"

namespace SQU {
	namespace UI {
		class OperatorsListComponent : public SynthEmilionWidget
		{
			Q_OBJECT

		public:
			OperatorsListComponent(QWidget *parent = Q_NULLPTR);
			~OperatorsListComponent();

		private:

			Ui::OperatorsListComponent ui;

			const int NB_OPERATORS = 10;
			const int NB_ACTIVATED_OPERATORS = 2;

			std::vector<std::unique_ptr<OperatorComponent>> operators;

			std::unique_ptr<OperatorComponent>& addOperator();

			QHBoxLayout* hLayout;
		};
	}
}