#pragma once
#include <QtWidgets/QApplication>
#include <QtWidgets/QAbstractButton>
#include "../Global/SynthEmilionWidget.h"
#include "SynthEmilionMessage.h"
#include "ui_global.h"

class UI_EXPORT SynthEmilionComponent : public SynthEmilionWidget
{
	Q_OBJECT

public:
	SynthEmilionComponent(int number, SQU::Comm::ComponentType componentType, QWidget *parent);
	~SynthEmilionComponent();

	int getNumber();

	void activate();
	void deactivate();


	QString getObjectFullName();

protected:
	void setActivationControl(QAbstractButton *button);
	void setDefaultBackColor(QString color);
	SQU::Comm::ComponentType componentType;
	void sendParameterChangeEventBool(SQU::Comm::ParameterType parameterType, bool value);
	void sendParameterChangeEventInt(SQU::Comm::ParameterType parameterType, int value);
	void sendParameterChangeEventDouble(SQU::Comm::ParameterType parameterType, double value);

	void afterSetupUi();

private slots:
	void activationChangedHandle(int state);
	bool eventFilter(QObject *obj, QEvent *event);

private:
	QString getObjectTypeName();
	QAbstractButton *activationButton;
	int number;
	void refreshActiveState(bool active);
	
};
