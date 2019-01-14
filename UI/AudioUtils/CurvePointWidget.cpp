#include "CurvePointWidget.h"

namespace SQU {
	namespace UI {
		CurvePointWidget::CurvePointWidget(QWidget *parent, int number)
			: QWidget(parent)
		{
			pointNumber = number;
			currentHorizontalScale = 10;
			currentVerticalScale = 1;
			setCurveAndLengthFunctions("sin(x)", "2*pi()");
		}

		void CurvePointWidget::mousePressEvent(QMouseEvent* event)
		{
			emit selected(this);
		}

		void CurvePointWidget::paintEvent(QPaintEvent *event)
		{
			if (imageIsGenerated)
			{
				if (heightOnLastPaint != height())
				{
					heightOnLastPaint = height();
					generateCurveImage();
				}

				QPainter painter(this);
				painter.drawPixmap(0, 0, curveImage);
			}
		}

		void CurvePointWidget::generateCurveImage()
		{
			imageIsGenerated = false;

			QPainterPath* linePainterPath = nullptr;
			QPainterPath* brushPainterPath = nullptr;

			double heightFactor = (height() - LINE_WIDTH) / 2;

			linePainterPath = nullptr;
			brushPainterPath = new QPainterPath(QPoint(0, height()));

			std::vector<double>::iterator it;
			double x = 0.0;

			double lastY;

			bool oneValueParsed = false;

			if (previousCurve != nullptr)
			{
				linePainterPath = new QPainterPath(QPoint(x, LINE_WIDTH + heightFactor - (previousCurve->getLastValue() * heightFactor)));
			}

			for (it = functionValues.begin(); it != functionValues.end(); it++)
			{
				oneValueParsed = true;

				double y = LINE_WIDTH + heightFactor - (*it * heightFactor);

				if (linePainterPath == nullptr)
				{
					linePainterPath = new QPainterPath(QPoint(x, y));
				}
				else
				{
					linePainterPath->lineTo(x, y);
				}

				if (!DRAW_LINE_ONLY)
				{
					brushPainterPath->lineTo(x, y);
				}

				x += CALCULATION_RESOLUTION;

				lastY = y;
			}

			if (oneValueParsed)
			{
				brushPainterPath->lineTo(x + 10, lastY);
				brushPainterPath->lineTo(x + 10, height());

				curveImage = QPixmap(width(), height());
				
				QPainter painter(&curveImage);
				painter.setRenderHint(QPainter::Antialiasing);
				painter.scale(currentHorizontalScale, 1);

				if (!DRAW_LINE_ONLY)
				{
					painter.setPen(Qt::PenStyle::NoPen);
					painter.setBrush(QBrush(QColor(180, 180, 255)));
					painter.drawPath(*brushPainterPath);
				}

				QPen pen(Qt::blue);
				pen.setWidth(LINE_WIDTH);
				pen.setStyle(Qt::PenStyle::SolidLine);
				pen.setCapStyle(Qt::PenCapStyle::SquareCap);
				pen.setJoinStyle(Qt::PenJoinStyle::MiterJoin);
				pen.setCosmetic(true);

				painter.setPen(pen);
				painter.setBrush(Qt::BrushStyle::NoBrush);
				painter.drawPath(*linePainterPath);


				imageIsGenerated = true;
			}
		}

		CurvePointWidget::~CurvePointWidget()
		{
		}

		void CurvePointWidget::setNumber(int num)
		{
			this->pointNumber = num;
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

		bool CurvePointWidget::isMathFunctionValid(QString fct)
		{
			double x;
			te_variable vars[] = { { "x", &x }, { "pi", &std::_Pi } };

			int err;
			te_expr *n = te_compile(fct.toStdString().c_str(), vars, 2, &err);

			if (n) {
				return true;
			}

			return false;
		}

		bool CurvePointWidget::isLengthFunctionValid(QString fct)
		{
			int err;
			double c = te_interp(fct.toStdString().c_str(), &err);

			if (err == 0) {
				return true;
			}

			return false;
		}

		void CurvePointWidget::setCurveFunction(QString fct)
		{
			if (fct != currentCurveFunction)
			{
				if (isMathFunctionValid(fct))
				{
					currentCurveFunction = fct;

					if (currentFunctionEval != nullptr)
					{
						te_free(currentFunctionEval);
					}

					te_variable vars[] = { { "x", &currentCalcTime } };
					int err;
					currentFunctionEval = te_compile(currentCurveFunction.toStdString().c_str(), vars, 1, &err);

					calculateValues();
					repaint();
				}
			}
		}

		void CurvePointWidget::setLengthFunction(QString fct)
		{
			if (fct != currentLengthFunction)
			{
				currentLengthFunction = fct;

				te_variable vars[] = { { } };

				int err;
				te_expr *n = te_compile(currentLengthFunction.toStdString().c_str(), vars, 0, &err);

				double currentVal = te_eval(n);

				setLength(currentVal);

				te_free(n);
			}
		}

		void CurvePointWidget::setLength(double length)
		{
			if (length != currentLength)
			{
				currentLength = length;
				adaptSize();
				calculateValues();
			}
		}

		void CurvePointWidget::setCurveAndLengthFunctions(QString curveFct, QString lengthFct)
		{
			bool calculate = false;

			if (curveFct != currentCurveFunction && isMathFunctionValid(curveFct))
			{
				currentCurveFunction = curveFct;

				if (currentFunctionEval != nullptr)
				{
					te_free(currentFunctionEval);
				}

				te_variable vars[] = { { "x", &currentCalcTime } };
				int err;
				currentFunctionEval = te_compile(currentCurveFunction.toStdString().c_str(), vars, 1, &err);

				calculate = true;
			}
			
			if (lengthFct != currentLengthFunction && isLengthFunctionValid(lengthFct))
			{
				currentLengthFunction = lengthFct;

				te_variable vars[] = { {} };

				int err;
				te_expr *n = te_compile(currentLengthFunction.toStdString().c_str(), vars, 0, &err);

				double currentVal = te_eval(n);

				if (currentLength != currentVal)
				{
					currentLength = currentVal;

					adaptSize();

					calculate = true;
				}

				te_free(n);
			}

			if (calculate)
			{
				calculateValues();
				repaint();
			}
		}

		void CurvePointWidget::adaptSize()
		{
			setMinimumWidth(currentLength * currentHorizontalScale);
			setMaximumWidth(currentLength * currentHorizontalScale);
			setFixedWidth(currentLength * currentHorizontalScale);
		}

		void CurvePointWidget::setHorizontalScale(double hScale)
		{
			setScale(hScale, currentVerticalScale);
		}


		void CurvePointWidget::setVerticalScale(double vScale)
		{
			setScale(currentHorizontalScale, vScale);
		}

		void CurvePointWidget::setScale(double hScale, double vScale)
		{
			bool changed = false;

			if (currentHorizontalScale != hScale)
			{
				changed = true;
				currentHorizontalScale = hScale;
			}

			if (currentVerticalScale != vScale)
			{
				changed = true;
				currentVerticalScale = vScale;
			}

			if (changed)
			{
				adaptSize();
				generateCurveImage();
				repaint();
			}
		}

		int CurvePointWidget::number()
		{
			return pointNumber;
		}

		QString CurvePointWidget::curveFunction()
		{
			return currentCurveFunction;
		}

		QString CurvePointWidget::lengthFunction()
		{
			return currentLengthFunction;
		}

		double CurvePointWidget::length()
		{
			return currentLength;
		}

		double CurvePointWidget::horizontalScale()
		{
			return currentHorizontalScale;
		}

		double CurvePointWidget::verticalScale()
		{
			return currentVerticalScale;
		}

		void CurvePointWidget::calculateValues()
		{
			functionValues.clear();

			for (double x = 0; x <= currentLength; x += CALCULATION_RESOLUTION)
			{
				double valForTime = getValueForTime(x);

				functionValues.emplace_back(valForTime);
			}

			generateCurveImage();
		}

		double CurvePointWidget::getValueForTime(double time)
		{
			currentCalcTime = time;
			double currentVal = te_eval(currentFunctionEval);

			return std::min<double>(std::max<double>(currentVal, -1), 1);
		}
	}
}