#pragma once

#include <QWidget>
#include <QPainter>
#include <QtCharts>
#include "tinyexpr.h"

namespace SQU {
	namespace UI {
		class CurvePointWidget : public QWidget
		{
			Q_OBJECT

		public:
			CurvePointWidget(QWidget *parent, int number);
			~CurvePointWidget();

			static bool isMathFunctionValid(QString fct);
			static bool isLengthFunctionValid(QString fct);

			void setNumber(int num);
			void setSelected(bool isSelected);
			void setCurveFunction(QString fct);
			void setLengthFunction(QString fct);
			void setHorizontalScale(double hScale);
			void setVerticalScale(double vScale);
			void setScale(double hScale, double vScale);

			void setCurveAndLengthFunctions(QString curveFct, QString lengthFct);

			int number();
			bool selected();
			QString curveFunction();
			QString lengthFunction();
			double length();
			double horizontalScale();
			double verticalScale();

			double getLastValue();

			void setPreviousCurve(CurvePointWidget* curve);
			void setNextCurve(CurvePointWidget* curve);

		signals:
			void clicked(CurvePointWidget* widget);

		protected:
			void paintEvent(QPaintEvent *event) override;

			void mousePressEvent(QMouseEvent* event) override;

		private:

			const int LINE_WIDTH = 1;
			const bool DRAW_LINE_ONLY = false;
			const double CALCULATION_RESOLUTION = 0.01;
			
			CurvePointWidget* previousCurve = nullptr;
			CurvePointWidget* nextCurve = nullptr;

			void setLength(double length);

			int pointNumber = 0;

			bool currentSelected;
			QString currentCurveFunction;
			QString currentLengthFunction;

			double currentLength;
			double currentHorizontalScale;
			double currentVerticalScale;

			std::vector<double> functionValues;

			void adaptSize();

			void calculateValues();
			double getValueForTime(double time);

			QPixmap curvePixmap;
			QPainterPath* linePainterPath = nullptr;
			QPainterPath* brushPainterPath = nullptr;
			bool pixmapNeedsGeneration = true;
			void generatePaintersPath();
			void generateCurvePixmap();

			double currentCalcTime = 0;
			te_expr *currentFunctionEval = nullptr;
		};
	}
}