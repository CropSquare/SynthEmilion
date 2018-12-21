#pragma once
#include <memory>
#include "SynthEmilionComponent.h"
#include "ComponentsList.h"
#include "OperatorComponent.h"
#include "EnvelopeComponent.h"
#include "FilterComponent.h"
#include "LfoComponent.h"
#include "ui_global.h"

namespace SQU {
	namespace UI {
		
		template<class T>
		class UI_EXPORT SpecializedComponentsList : public ComponentsList
		{
		public:
			SpecializedComponentsList(QWidget *parent = Q_NULLPTR);
			~SpecializedComponentsList();

		private:
			std::vector<std::unique_ptr<T>> components;

			std::unique_ptr<T>& addComponent();

			int getNbComponents();
			int getNbActivatedComponents();

			void componentAdded(std::unique_ptr<T> &newComponent);

			QString getListTitle();
		};


		typedef SpecializedComponentsList<OperatorComponent> OperatorsList;
		typedef SpecializedComponentsList<EnvelopeComponent> EnvelopesList;
		typedef SpecializedComponentsList<FilterComponent> FiltersList;
		typedef SpecializedComponentsList<LfoComponent> LfosList;
	}
}
