#pragma once

#include <QWidget>
#include "../GeneratedFiles/ui_OperatorPanel.h"
#include "../AudioUtils/CurvePointWidget.h"

namespace SQU {
	namespace UI {
		class OperatorComponent;

		class OperatorPanel : public QWidget
		{
			Q_OBJECT

		public:
			OperatorPanel(OperatorComponent *linkedOperatorComponent);
			~OperatorPanel();

			void notifyPitch(int pitch);

		private:
			Ui::OperatorPanel ui;
			OperatorComponent* linkedOperatorComponent;
			int getPitchFromParams(int octave, int note, int fine);
			void getParamsFromPitch(int pitch, int &octave, int &note, int &fine);

			QHBoxLayout* componentsList_hLayout;

			CurvePointWidget* curvePointWidget;
			CurvePointWidget* curvePointWidget2;
		};
	}
}