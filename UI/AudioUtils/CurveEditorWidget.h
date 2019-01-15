#pragma once

#include <memory>
#include <QWidget>
#include "../GeneratedFiles/ui_CurveEditorWidget.h"
#include "CurvePointWidget.h"

namespace SQU {
	namespace UI {
		class CurveEditorWidget : public QWidget
		{
			Q_OBJECT

		public:
			CurveEditorWidget(QWidget *parent = Q_NULLPTR);
			~CurveEditorWidget();

		protected:
			bool eventFilter(QObject *object, QEvent *event) override;

		private slots:
			
			void validateCurrentPointDataHandle();
			void deleteCurrentPointHandle();
			void addNewPointHandle();
			void selectedPointChangedHandle(CurvePointWidget* point);
			void functionTextChanged(const QString &);
			void lengthTextChanged(const QString &);

		private:
			Ui::CurveEditorWidget ui;

			QHBoxLayout* componentsList_hLayout;

			std::vector<std::unique_ptr<CurvePointWidget>> points;

			std::unique_ptr<CurvePointWidget>& addPoint();


			void changeHorizontalZoom(double zoom);
			double currentHorizontalZoom = 10.0;

			void changeVerticalZoom(double zoom);
			double currentVerticalZoom = 1.0;

			CurvePointWidget* selectedPoint = nullptr;
			void selectedPointChanged(CurvePointWidget* selectedPoint);

		};
	}
}