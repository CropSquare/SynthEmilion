#include "OperatorPanel.h"
#include "../Components/OperatorComponent.h"

namespace SQU {
	namespace UI {
		OperatorPanel::OperatorPanel(OperatorComponent *linkedOperatorComponent)
			: QWidget()
		{
			ui.setupUi(this);

			this->linkedOperatorComponent = linkedOperatorComponent;

			componentsList_hLayout = new QHBoxLayout(ui.scrollAreaWidgetContents);
			componentsList_hLayout->setSpacing(0);
			componentsList_hLayout->setMargin(0);

			curvePointWidget = new CurvePointWidget(nullptr);
			componentsList_hLayout->addWidget(curvePointWidget, 0, Qt::AlignLeft);
			curvePointWidget->show();

			curvePointWidget2 = new CurvePointWidget(nullptr);
			curvePointWidget2->setMathFunction("tan(x)");
			curvePointWidget2->setFunctionLength(40);
			curvePointWidget2->setPreviousCurve(curvePointWidget);

			curvePointWidget->setNextCurve(curvePointWidget2);

			componentsList_hLayout->addWidget(curvePointWidget2, 0, Qt::AlignLeft);
			curvePointWidget2->show();
			
		}

		OperatorPanel::~OperatorPanel()
		{
		}

		void OperatorPanel::notifyPitch(int pitch)
		{
			int octave = 0;
			int note = 0;
			int fine = 0;

			getParamsFromPitch(pitch, octave, note, fine);

			ui.octave_dial->setValue(octave);
			ui.note_dial->setValue(note);
			ui.fine_dial->setValue(fine);
		}

		int OperatorPanel::getPitchFromParams(int octave, int note, int fine)
		{
			return ((octave * 12) + note) * 100 + fine;
		}

		void OperatorPanel::getParamsFromPitch(int pitch, int &octave, int &note, int &fine)
		{
			int multiplier = 1;
			if (pitch < 0)
			{
				multiplier = -1;
			}

			pitch = pitch * multiplier;

			fine = pitch % 100;

			pitch = (pitch - fine) / 100;

			note = pitch % 12;

			octave = (pitch - note) / 12;

			octave *= multiplier;
			note *= multiplier;
			fine *= multiplier;
		}
	}
}