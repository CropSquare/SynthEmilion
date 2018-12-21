#pragma once

#include <QWidget>
#include "../GeneratedFiles/ui_EnvelopeComponent.h"
#include "../Global/SynthEmilionWidget.h"
#include "SynthEmilionComponent.h"
#include "SynthEmilionMessage.h"
#include "ui_global.h"

namespace SQU {
	namespace UI {
		class UI_EXPORT EnvelopeComponent : public SynthEmilionComponent
		{
			Q_OBJECT

		public:
			EnvelopeComponent(int number, QWidget *parent = Q_NULLPTR);
			~EnvelopeComponent();

		private slots:
			void attackChangedHandle(int value);
			void attackBendChangedHandle(int value);
			void decayChangedHandle(int value);
			void decayBendChangedHandle(int value);
			void sustainChangedHandle(int value);
			void releaseChangedHandle(int value);
			void releaseBendChangedHandle(int value);

		private:
			Ui::EnvelopeComponent ui;
		};
	}
}