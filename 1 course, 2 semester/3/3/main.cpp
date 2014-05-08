#include "mainwindow.h"
#include "testcalculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	TestCalculator test;
	QTest::qExec(&test);

	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	return a.exec();
}
