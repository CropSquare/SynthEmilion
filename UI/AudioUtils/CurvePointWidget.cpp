#include "CurvePointWidget.h"

namespace SQU {
	namespace UI {
		CurvePointWidget::CurvePointWidget(QWidget *parent)
			: QWidget(parent)
		{
			currentMathFunction = "sin(x)";
			currentZoom = 10;
			currentResolution = 0.1;
			currentFunctionLength = 60;
			adaptWidth();
			
			calculateValues();
		}

		void CurvePointWidget::paintEvent(QPaintEvent *event)
		{
			int penWidth = 5;
			double heightFactor = (height() - penWidth) / 2;

			QPainterPath* linePainterPath = nullptr;
			QPainterPath* brushPainterPath = new QPainterPath(QPoint(0, height()));

			std::vector<double>::iterator it;
			double x = 0.0;

			double lastY;

			if (previousCurve != nullptr)
			{
				linePainterPath = new QPainterPath(QPoint(x, penWidth + heightFactor - (previousCurve->getLastValue() * heightFactor)));
			}

			for (it = functionValues.begin(); it != functionValues.end(); it++)
			{
				double y = penWidth + heightFactor - (*it * heightFactor);

				if (linePainterPath == nullptr)
				{
					linePainterPath = new QPainterPath(QPoint(x, y));
				}
				else
				{
					linePainterPath->lineTo(x, y);
				}

				brushPainterPath->lineTo(x, y);

				x += currentResolution;

				lastY = y;
			}

			brushPainterPath->lineTo(x+10, lastY);
			brushPainterPath->lineTo(x+10, height());

			if (linePainterPath != nullptr)
			{
				QPainter painter(this);
				painter.setRenderHint(QPainter::Antialiasing);
				painter.scale(currentZoom, 1);

				QPen pen(Qt::blue);
				pen.setWidth(penWidth);
				pen.setStyle(Qt::PenStyle::SolidLine);
				pen.setCapStyle(Qt::PenCapStyle::RoundCap);
				pen.setJoinStyle(Qt::PenJoinStyle::RoundJoin);
				pen.setCosmetic(true);

				painter.setPen(pen);
				painter.drawPath(*linePainterPath);

				painter.setPen(Qt::PenStyle::NoPen);
				painter.setBrush(QBrush(QColor(180,180,255)));
				painter.drawPath(*brushPainterPath);
				
				

				/*painterPath = new QPainterPath();
				painterPath->addEllipse(QPoint(x, lastY), 5 / currentZoom, 5);

				painter.setBrush(QBrush(Qt::red));

				painter.drawPath(*painterPath);*/
			}
		}

		CurvePointWidget::~CurvePointWidget()
		{
		}

		void CurvePointWidget::setPreviousCurve(CurvePointWidget* curve)
		{
			previousCurve = curve;
		}
		void CurvePointWidget::setNextCurve(CurvePointWidget* curve)
		{
			nextCurve = curve;
		}

		double CurvePointWidget::getLastValue()
		{
			return functionValues.at(functionValues.size() - 1);
		}

		bool CurvePointWidget::isFunctionValid(QString fct)
		{
			return fct == "x" || fct == "sin(x)" || fct == "cos(x)" || fct == "tan(x)";
		}

		void CurvePointWidget::setMathFunction(QString fct)
		{
			if (isFunctionValid(fct))
			{
				currentMathFunction = fct;
				calculateValues();
			}
		}

		void CurvePointWidget::adaptWidth()
		{
			setMinimumWidth(currentFunctionLength * currentZoom);
			setMaximumWidth(currentFunctionLength * currentZoom);
			setFixedWidth(currentFunctionLength * currentZoom);
		}

		void CurvePointWidget::setFunctionLength(double length)
		{
			currentFunctionLength = length;
			adaptWidth();
			calculateValues();
		}

		void CurvePointWidget::setZoom(double zoom)
		{
			currentZoom = zoom;
			adaptWidth();
		}

		QString CurvePointWidget::mathFunction()
		{
			return currentMathFunction;
		}

		double CurvePointWidget::functionLength()
		{
			return currentFunctionLength;
		}

		double CurvePointWidget::zoom()
		{
			return currentZoom;
		}

		void CurvePointWidget::calculateValues()
		{
			functionValues.clear();

			for (double x = 0; x <= currentFunctionLength; x += currentResolution)
			{
				double valForTime = getValueForTime(x);

				functionValues.emplace_back(valForTime);
			}
		}

		double CurvePointWidget::getValueForTime(double time)
		{
			double currentVal = 0;

			if (currentMathFunction == "x")
			{
				currentVal = time;
			}
			else if (currentMathFunction == "sin(x)")
			{
				currentVal = sin(time);
			}
			else if (currentMathFunction == "cos(x)")
			{
				currentVal = cos(time);
			}
			else if (currentMathFunction == "tan(x)")
			{
				currentVal = tan(time);
			}

			return  std::min<double>(std::max<double>(currentVal, -1), 1);
		}
	}
}