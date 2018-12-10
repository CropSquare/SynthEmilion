#pragma once

#include <QWidget>

class SynthEmilionComponent;

namespace SQU {
	namespace UI {
		class ComponentPanel : public QWidget
		{
			Q_OBJECT

		public:
			ComponentPanel(SynthEmilionComponent *linkedComponent, QWidget *parent);
			~ComponentPanel();

		private:
			SynthEmilionComponent* linkedComponent;
		};
	}
}