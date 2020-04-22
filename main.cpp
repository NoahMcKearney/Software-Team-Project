#include "stdafx.h"
#include "GamePicker.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GamePicker w;
	w.show();
	return a.exec();
}
