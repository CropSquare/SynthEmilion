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


			opList = new OperatorsList(this);
			opList->move(0, ui.activeCompLabel->y() + ui.activeCompLabel->height());
			opList->show();
			opList->setEventsReceiver(this);

			envList = new EnvelopesList(this);
			envList->move(opList->x() + opList->width() + 5, opList->y());
			envList->show();
			envList->setEventsReceiver(this);


			fltList = new FiltersList(this);
			fltList->move(opList->x(), envList->y() + envList->height() + 5);
			fltList->show();
			fltList->setEventsReceiver(this);

			lfosList = new LfosList(this);
			lfosList->move(fltList->x() + fltList->width() + 5, fltList->y());
			lfosList->show();
			lfosList->setEventsReceiver(this);


			mainComponent = new MainComponent(this);
			mainComponent->move(envList->x() + envList->width() + 5, opList->y());
			mainComponent->setFixedHeight(lfosList->y() + lfosList->height() - mainComponent->y());
			mainComponent->show();
			mainComponent->setEventsReceiver(this);


			setFixedWidth(mainComponent->x() + mainComponent->width());
			setFixedHeight(mainComponent->y() + mainComponent->height());
			
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

				if (currentlyFocusedComponent != nullptr && currentlyFocusedComponent->associatedPanel != nullptr)
				{
					currentlyFocusedComponent->associatedPanel->setParent(Q_NULLPTR);
				}
				
				if (component->associatedPanel != nullptr)
				{
					component->associatedPanel->setParent(this);
					component->associatedPanel->move(0, mainComponent->y() + mainComponent->height() + 5);
					component->associatedPanel->setFixedWidth(mainComponent->x() + mainComponent->width());
					component->associatedPanel->show();

					setFixedHeight(component->associatedPanel->y() + component->associatedPanel->height());
				}
				else
				{
					setFixedHeight(mainComponent->y() + mainComponent->height());
				}

				this->resize(this->geometry().width(), this->geometry().height());

				currentlyFocusedComponent = component;
			}
		}
	}
}