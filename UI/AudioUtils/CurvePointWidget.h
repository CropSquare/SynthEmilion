#pragma once

#include <QWidget>
#include <QPainter>
#include <QtCharts>

namespace SQU {
	namespace UI {
		class CurvePointWidget : public QWidget
		{
			Q_OBJECT

		public:
			CurvePointWidget(QWidget *parent);
			~CurvePointWidget();

			static bool isFunctionValid(QString fct);

			void setMathFunction(QString fct);
			void setFunctionLength(double length);
			void setZoom(double zoom);

			QString mathFunction();
			double functionLength();
			double zoom();

			double getLastValue();

			void setPreviousCurve(CurvePointWidget* curve);
			void setNextCurve(CurvePointWidget* curve);

		protected:
			void paintEvent(QPaintEvent *event) override;

		private:
			CurvePointWidget* previousCurve = nullptr;
			CurvePointWidget* nextCurve = nullptr;

			QString currentMathFunction;
			double currentFunctionLength;
			double currentResolution;
			double currentZoom;

			std::vector<double> functionValues;

			void adaptWidth();

			void calculateValues();
			double getValueForTime(double time);
		};
	}
}