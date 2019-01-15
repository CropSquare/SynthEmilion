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

			connect(ui.currentPointFunction_lineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(functionTextChanged(const QString &)));

			connect(ui.currentPointLength_lineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(lengthTextChanged(const QString &)));

			componentsList_hLayout = new QHBoxLayout(ui.scrollAreaWidgetContents);
			componentsList_hLayout->setSpacing(0);
			componentsList_hLayout->setMargin(0);
			componentsList_hLayout->setAlignment(Qt::AlignLeft);

			CurvePointWidget* point1 = addPoint().get();

			ui.deleteCurrentPoint_pushButton->setEnabled(false);

			// Events filter
			ui.currentPointFunction_lineEdit->installEventFilter(this);
			ui.currentPointLength_lineEdit->installEventFilter(this);
			ui.curve_scrollArea->horizontalScrollBar()->installEventFilter(this);
			ui.scrollAreaWidgetContents->installEventFilter(this);
			this->installEventFilter(this);
		}


		void CurveEditorWidget::functionTextChanged(const QString &text)
		{
			if (CurvePointWidget::isMathFunctionValid(text))
			{
				ui.currentPointFunction_lineEdit->setStyleSheet("");
			}
			else
			{
				ui.currentPointFunction_lineEdit->setStyleSheet("color:red;");
			}
		}

		void CurveEditorWidget::lengthTextChanged(const QString &text)
		{
			if (CurvePointWidget::isLengthFunctionValid(text))
			{
				ui.currentPointLength_lineEdit->setStyleSheet("");
			}
			else
			{
				ui.currentPointLength_lineEdit->setStyleSheet("color:red;");
			}
		}

		CurveEditorWidget::~CurveEditorWidget()
		{
		}

		bool CurveEditorWidget::eventFilter(QObject *object, QEvent *event)
		{
			bool eventAccept = false;

			if (object == this && event->type() == QEvent::Resize)
			{
				QResizeEvent *resizeEvent = static_cast<QResizeEvent *>(event);

				if (resizeEvent->oldSize().height() != resizeEvent->size().height())
				{
					// Restore zoom according to scroll area
					changeVerticalZoom(currentVerticalZoom);
				}
			}
			else if (object == ui.curve_scrollArea->horizontalScrollBar() && (event->type() == QEvent::Show || event->type() == QEvent::Hide))
			{
				changeVerticalZoom(currentVerticalZoom);
			}
			else if (object == ui.scrollAreaWidgetContents && event->type() == QEvent::Wheel)
			{
				QWheelEvent *wheelEvent = static_cast<QWheelEvent *>(event);

				int delta = wheelEvent->delta();

				if (wheelEvent->modifiers().testFlag(Qt::ControlModifier))
				{
					// Change horizontal zoom
					if (delta < 0)
					{
						changeHorizontalZoom(currentHorizontalZoom / 2);
					}
					else if (delta > 0)
					{
						changeHorizontalZoom(currentHorizontalZoom * 2);
					}
				}
				else if (wheelEvent->modifiers().testFlag(Qt::AltModifier))
				{
					// Change vertical zoom
					if (delta < 0)
					{
						changeVerticalZoom(currentVerticalZoom / 2);
					}
					else if (delta > 0)
					{
						changeVerticalZoom(currentVerticalZoom * 2);
					}
				}
				else if (!ui.curve_scrollArea->verticalScrollBar()->isVisible() || wheelEvent->modifiers().testFlag(Qt::ShiftModifier))
				{
					ui.curve_scrollArea->horizontalScrollBar()->setValue(ui.curve_scrollArea->horizontalScrollBar()->value() - delta);
				}
				else
				{
					ui.curve_scrollArea->verticalScrollBar()->setValue(ui.curve_scrollArea->verticalScrollBar()->value() - delta);
				}

				eventAccept = true;
			}
			else if (event->type() == QEvent::KeyPress)
			{
				QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

				int key = keyEvent->key();

				if (key == Qt::Key_Enter || key == Qt::Key::Key_Return)
				{
					// Validation attempt
					if (object == ui.currentPointFunction_lineEdit)
					{
						// Validate curve function
						validateCurrentPointDataHandle();

						if (CurvePointWidget::isMathFunctionValid(ui.currentPointFunction_lineEdit->text()))
						{
							// Focus on length
							ui.currentPointLength_lineEdit->setFocus();
						}

						eventAccept = true;
					}
					else if (object == ui.currentPointLength_lineEdit)
					{
						// Validate curve length
						validateCurrentPointDataHandle();
						
						if (CurvePointWidget::isLengthFunctionValid(ui.currentPointLength_lineEdit->text()))
						{
							// Focus on validate button
							ui.currentPointDataValidation_pushButton->setFocus();
						}

						eventAccept = true;
					}
				}
				else if (key == Qt::Key::Key_Escape)
				{
					// Cancel input (restore two values)
					ui.currentPointFunction_lineEdit->setText(selectedPoint->curveFunction());
					ui.currentPointLength_lineEdit->setText(selectedPoint->lengthFunction());
					eventAccept = true;
				}
			}

			if (eventAccept)
			{
				event->accept();
			}
			return eventAccept;
		}

		void CurveEditorWidget::changeHorizontalZoom(double zoom)
		{
			currentHorizontalZoom = zoom;

			std::vector<std::unique_ptr<CurvePointWidget>>::iterator it;

			for (it = points.begin(); it != points.end(); it++)
			{
				(*it)->setHorizontalScale(currentHorizontalZoom);
			}
		}

		void CurveEditorWidget::changeVerticalZoom(double zoom)
		{
			currentVerticalZoom = zoom;

			std::vector<std::unique_ptr<CurvePointWidget>>::iterator it;

			int scrollHeight = ui.curve_scrollArea->horizontalScrollBar()->isVisible() ? ui.curve_scrollArea->horizontalScrollBar()->height() / 2 : 0;

			for (it = points.begin(); it != points.end(); it++)
			{
				(*it)->setVerticalScale(currentVerticalZoom * ((ui.curve_scrollArea->height()-2) / 2) - scrollHeight);
			}
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
			newPoint.get()->setScale(currentHorizontalZoom, currentVerticalZoom * ((ui.curve_scrollArea->height() - 2) / 2));
			componentsList_hLayout->addWidget(newPoint.get(), 0, Qt::AlignLeft);
			newPoint.get()->show();

			connect(newPoint.get(), SIGNAL(clicked(CurvePointWidget*)), this, SLOT(selectedPointChangedHandle(CurvePointWidget*)));

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
			if (this->selectedPoint != nullptr)
			{
				this->selectedPoint->setSelected(false);
			}

			this->selectedPoint = point;

			ui.currentPointFunction_lineEdit->setStyleSheet("background-color:white;");
			ui.currentPointLength_lineEdit->setStyleSheet("background-color:white;");

			ui.currentPoint_label->setText("Point " + QString::number(selectedPoint->number()));
			ui.currentPointFunction_lineEdit->setText(selectedPoint->curveFunction());
			ui.currentPointLength_lineEdit->setText(selectedPoint->lengthFunction());

			point->setSelected(true);
		}

	}
}