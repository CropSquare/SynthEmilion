#include "SpecializedComponentsList.h"

namespace SQU {
	namespace UI {
		template <class T>
		SpecializedComponentsList<T>::SpecializedComponentsList(QWidget *parent)
			: ComponentsList(parent)
		{
			ui.listTitle_label->setText(getListTitle());

			for (int i = 0; i < getNbComponents(); i++)
			{
				std::unique_ptr<T>& newComponent = addComponent();

				if (getNbActivatedComponents() > 0 && i < getNbActivatedComponents())
				{
					newComponent->activate();
				}
				else
				{
					newComponent->deactivate();
				}
			}
		}


		template <class T>
		SpecializedComponentsList<T>::~SpecializedComponentsList()
		{
		}

		template <class T>
		void SpecializedComponentsList<T>::componentAdded(std::unique_ptr<T> &newComponent)
		{
			newComponent->setEventsReceiver(this);

			componentsList_hLayout->addWidget(newComponent.get(), 0, Qt::AlignLeft);

			setFixedHeight(ui.scrollArea->y() + ui.scrollArea->height());
		}


		///OPERATORS

		template <>
		QString OperatorsList::getListTitle()
		{
			return "Operators";
		}

		template <>
		int OperatorsList::getNbComponents()
		{
			return 10;
		}

		template <>
		int OperatorsList::getNbActivatedComponents()
		{
			return 2;
		}

		template <>
		std::unique_ptr<OperatorComponent>& OperatorsList::addComponent()
		{
			components.emplace_back(new OperatorComponent(components.size(), nullptr));

			std::unique_ptr<OperatorComponent> &newOp = components.at(components.size() - 1);

			ui.scrollArea->setFixedHeight(newOp->height() + qApp->style()->pixelMetric(QStyle::PM_ScrollBarExtent));

			componentAdded(newOp);

			return newOp;
		}

		///

		///ENVELOPES

		template <>
		QString EnvelopesList::getListTitle()
		{
			return "Envelopes";
		}

		template <>
		int EnvelopesList::getNbComponents()
		{
			return 10;
		}

		template <>
		int EnvelopesList::getNbActivatedComponents()
		{
			return 2;
		}

		template <>
		std::unique_ptr<EnvelopeComponent>& EnvelopesList::addComponent()
		{
			components.emplace_back(new EnvelopeComponent(components.size(), nullptr));

			std::unique_ptr<EnvelopeComponent> &newEnv = components.at(components.size() - 1);

			ui.scrollArea->setFixedHeight(newEnv->height() + qApp->style()->pixelMetric(QStyle::PM_ScrollBarExtent));

			componentAdded(newEnv);

			return newEnv;
		}

		///

		///FILTERS

		template <>
		QString FiltersList::getListTitle()
		{
			return "Filters";
		}

		template <>
		int FiltersList::getNbComponents()
		{
			return 10;
		}

		template <>
		int FiltersList::getNbActivatedComponents()
		{
			return 2;
		}

		template <>
		std::unique_ptr<FilterComponent>& FiltersList::addComponent()
		{
			components.emplace_back(new FilterComponent(components.size(), nullptr));

			std::unique_ptr<FilterComponent> &newFlt = components.at(components.size() - 1);

			ui.scrollArea->setFixedHeight(newFlt->height() + qApp->style()->pixelMetric(QStyle::PM_ScrollBarExtent));

			componentAdded(newFlt);

			return newFlt;
		}

		///

		///LFOS

		template <>
		QString LfosList::getListTitle()
		{
			return "LFOs";
		}

		template <>
		int LfosList::getNbComponents()
		{
			return 10;
		}

		template <>
		int LfosList::getNbActivatedComponents()
		{
			return 2;
		}

		template <>
		std::unique_ptr<LfoComponent>& LfosList::addComponent()
		{
			components.emplace_back(new LfoComponent(components.size(), nullptr));

			std::unique_ptr<LfoComponent> &newLfo = components.at(components.size() - 1);

			ui.scrollArea->setFixedHeight(newLfo->height() + qApp->style()->pixelMetric(QStyle::PM_ScrollBarExtent));

			componentAdded(newLfo);

			return newLfo;
		}

		///
	}
}