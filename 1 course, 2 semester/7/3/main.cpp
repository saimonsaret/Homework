#include "mainwindow.h"
#include "testgame.h"
#include <QApplication>

int main(int argc, char *argv[])
{

	TestGame test;
	QTest::qExec(&test);

	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	return a.exec();
}
