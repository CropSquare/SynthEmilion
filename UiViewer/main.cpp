#include "UiViewer.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	UiViewer w;
	w.show();
	return a.exec();
}