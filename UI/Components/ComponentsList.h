#pragma once

#include <QWidget>
#include "../GeneratedFiles/ui_ComponentsList.h"
#include "../Global/SynthEmilionWidget.h"
#include <QHBoxLayout>

namespace SQU {
	namespace UI {
		class UI_EXPORT ComponentsList : public SynthEmilionWidget
		{
			Q_OBJECT

		public:
			ComponentsList(QWidget *parent = Q_NULLPTR);
			~ComponentsList();
			
		protected:
			Ui::ComponentsList ui;
			
			QHBoxLayout* componentsList_hLayout;
		};
	}
}

