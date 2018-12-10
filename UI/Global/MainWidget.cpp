#include "MainWidget.h"
#include <qfile.h>
#include "../Events/SynthEmilionEvent.h"
#include "../Events/ComponentFocusEvent.h"

namespace SQU {
	namespace UI {
		MainWidget::MainWidget(QWidget *parent)
			: SynthEmilionWidget(parent)
		{
			ui.setupUi(this);

			connect(ui.reloadQss_button, SIGNAL(clicked()), this, SLOT(reloadQss()));


			opList = new OperatorsListComponent(this);
			opList->show();
			opList->setEventsReceiver(this);

			paramEventNb = 0;
			activeEventNb = 0;

			reloadQss();
		}

		MainWidget::~MainWidget()
		{
		}

		void MainWidget::reloadQss()
		{
			QString path = QCoreApplication::applicationDirPath();
			path.append("/stylesheet.qss");
			QFile styleFile(path);

			if (styleFile.exists())
			{
				styleFile.open(QFile::ReadOnly);
				QString styleSheet = QLatin1String(styleFile.readAll());

				this->setStyleSheet(styleSheet);
			}
		}

		void MainWidget::notifySynthEmilionMessage(std::shared_ptr<Comm::SynthEmilionMessage> message)
		{
			paramEventNb++;
			ui.paramChangeLabel->setText("EV " + QString::number(paramEventNb) + " : Parameter " + QString::number(message->parameter) + " in component of type " + QString::number(message->component) + " with id " + QString::number(message->componentNumber) + " was changed");
		}

		void MainWidget::notifyComponentFocus(SynthEmilionComponent *component)
		{
			if (currentlyFocusedComponent != component)
			{
				activeEventNb++;
				ui.activeCompLabel->setText("EV " + QString::number(activeEventNb) + " : Component focused: " + component->getObjectFullName());

				currentlyFocusedComponent = component;
			}
		}
	}
}