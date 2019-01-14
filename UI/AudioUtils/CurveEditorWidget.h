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
			void wheelEvent(QWheelEvent *event) override;

		private slots:
			
			void validateCurrentPointDataHandle();
			void deleteCurrentPointHandle();
			void addNewPointHandle();
			void selectedPointChangedHandle(CurvePointWidget* point);

			void zoomInCurve();
			void zoomOutCurve();

		private:
			Ui::CurveEditorWidget ui;

			QHBoxLayout* componentsList_hLayout;

			std::vector<std::unique_ptr<CurvePointWidget>> points;

			std::unique_ptr<CurvePointWidget>& addPoint();


			void changeZoom(double zoom);
			double currentZoom = 10.0;

			CurvePointWidget* selectedPoint;
			void selectedPointChanged(CurvePointWidget* selectedPoint);

		};
	}
}