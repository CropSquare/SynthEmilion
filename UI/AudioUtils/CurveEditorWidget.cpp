#include "CurveEditorWidget.h"

namespace SQU {
	namespace UI {
		CurveEditorWidget::CurveEditorWidget(QWidget *parent)
			: QWidget(parent)
		{
			ui.setupUi(this);

			connect(ui.addPoint_pushButton, SIGNAL(clicked()), this, SLOT(addNewPointHandle()));
			connect(ui.currentPointDataValidation_pushButton, SIGNAL(clicked()), this, SLOT(validateCurrentPointDataHandle()));
			connect(ui.deleteCurrentPoint_pushButton, SIGNAL(clicked()), this, SLOT(deleteCurrentPointHandle()));

			connect (ui.zoomMinus_pushButton, SIGNAL(clicked()), this, SLOT(zoomOutCurve()));
			connect(ui.zoomPlus_pushButton, SIGNAL(clicked()), this, SLOT(zoomInCurve()));

			componentsList_hLayout = new QHBoxLayout(ui.scrollAreaWidgetContents);
			componentsList_hLayout->setSpacing(0);
			componentsList_hLayout->setMargin(0);
			componentsList_hLayout->setAlignment(Qt::AlignLeft);

			CurvePointWidget* point1 = addPoint().get();

			ui.deleteCurrentPoint_pushButton->setEnabled(false);
		}

		CurveEditorWidget::~CurveEditorWidget()
		{
		}

		void CurveEditorWidget::wheelEvent(QWheelEvent *event)
		{
			int delta = event->delta();

			if (event->modifiers().testFlag(Qt::ControlModifier))
			{
				if (delta < 0)
				{
					changeZoom(currentZoom / 2);
				}
				else if (delta > 0)
				{
					changeZoom(currentZoom * 2);
				}
			}
			else if (!ui.operatorCurve_scrollArea->verticalScrollBar()->isVisible() || event->modifiers().testFlag(Qt::ShiftModifier))
			{
				ui.operatorCurve_scrollArea->horizontalScrollBar()->setValue(ui.operatorCurve_scrollArea->horizontalScrollBar()->value() - delta);
			}
			else
			{
				QWidget::wheelEvent(event);
			}
		}

		void CurveEditorWidget::changeZoom(double zoom)
		{
			currentZoom = zoom;

			std::vector<std::unique_ptr<CurvePointWidget>>::iterator it;

			for (it = points.begin(); it != points.end(); it++)
			{
				(*it)->setHorizontalScale(currentZoom);
			}
		}

		void CurveEditorWidget::zoomInCurve()
		{
			changeZoom(currentZoom * 2);
		}

		void CurveEditorWidget::zoomOutCurve()
		{
			changeZoom(currentZoom / 2);
		}

		std::unique_ptr<CurvePointWidget>& CurveEditorWidget::addPoint()
		{
			CurvePointWidget* previous = nullptr;

			if (points.size() > 0)
			{
				previous = points.at(points.size() - 1).get();
			}

			points.emplace_back(new CurvePointWidget(nullptr, points.size() + 1));

			std::unique_ptr<CurvePointWidget> &newPoint = points.at(points.size() - 1);
			newPoint.get()->setHorizontalScale(currentZoom);
			componentsList_hLayout->addWidget(newPoint.get(), 0, Qt::AlignLeft);
			newPoint.get()->show();

			connect(newPoint.get(), SIGNAL(selected(CurvePointWidget*)), this, SLOT(selectedPointChangedHandle(CurvePointWidget*)));

			if (previous != nullptr)
			{
				previous->setNextCurve(newPoint.get());
				newPoint.get()->setPreviousCurve(previous);
			}
			
			selectedPointChangedHandle(newPoint.get());

			ui.deleteCurrentPoint_pushButton->setEnabled(points.size() > 1);

			return newPoint;
		}

		void CurveEditorWidget::validateCurrentPointDataHandle()
		{
			if (!CurvePointWidget::isMathFunctionValid(ui.currentPointFunction_lineEdit->text()))
			{
				ui.currentPointFunction_lineEdit->setStyleSheet("background-color:red;");
			}
			else
			{
				ui.currentPointFunction_lineEdit->setStyleSheet("background-color:white;");
			}

			if (!CurvePointWidget::isLengthFunctionValid(ui.currentPointLength_lineEdit->text()))
			{
				ui.currentPointLength_lineEdit->setStyleSheet("background-color:red;");
			}
			else
			{
				ui.currentPointLength_lineEdit->setStyleSheet("background-color:white;");
			}

			selectedPoint->setCurveAndLengthFunctions(ui.currentPointFunction_lineEdit->text(), ui.currentPointLength_lineEdit->text());
		}

		void CurveEditorWidget::deleteCurrentPointHandle()
		{
			CurvePointWidget* toDelete = this->selectedPoint;

			bool toDeleteFound = false;
			int currentNumber = 0;
			CurvePointWidget* beforeDeleted = nullptr;
			CurvePointWidget* afterDeleted = nullptr;

			std::vector<std::unique_ptr<CurvePointWidget>>::iterator it;

			for (it = points.begin(); it != points.end(); it++)
			{
				currentNumber++;

				bool isToDelete = (*it)->number() == toDelete->number();

				if (isToDelete)
				{
					toDeleteFound = true;
				}

				if (!toDeleteFound)
				{
					beforeDeleted = it->get();
				}

				if (toDeleteFound && !isToDelete)
				{
					(*it)->setNumber(currentNumber - 1);

					if (afterDeleted == nullptr)
					{
						afterDeleted = it->get();
					}
				}
			}

			if (beforeDeleted != nullptr)
			{
				beforeDeleted->setNextCurve(afterDeleted);
				selectedPointChangedHandle(beforeDeleted);
			}

			if (afterDeleted != nullptr)
			{
				afterDeleted->setPreviousCurve(beforeDeleted);

				if (beforeDeleted == nullptr)
				{
					selectedPointChangedHandle(afterDeleted);
				}
			}

			toDelete->setNextCurve(nullptr);
			toDelete->setPreviousCurve(nullptr);

			points.erase(points.begin() + toDelete->number() - 1);

			ui.deleteCurrentPoint_pushButton->setEnabled(points.size() > 1);
		}

		void CurveEditorWidget::addNewPointHandle()
		{
			addPoint();
		}

		void CurveEditorWidget::selectedPointChangedHandle(CurvePointWidget* point)
		{
			this->selectedPoint = point;

			ui.currentPointFunction_lineEdit->setStyleSheet("background-color:white;");
			ui.currentPointLength_lineEdit->setStyleSheet("background-color:white;");

			ui.currentPoint_label->setText("Point " + QString::number(selectedPoint->number()));
			ui.currentPointFunction_lineEdit->setText(selectedPoint->curveFunction());
			ui.currentPointLength_lineEdit->setText(selectedPoint->lengthFunction());
		}

	}
}