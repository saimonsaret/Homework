#include "mainwindow.h"
#include "testcalculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{

	TestCalculator test;
	QTest::qExec(&test);

	QApplication a(argc, argv);
	MainWindow window;
	window.show();

	return a.exec();
}
