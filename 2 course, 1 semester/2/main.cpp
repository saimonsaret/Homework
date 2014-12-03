#include "mainwindow.h"
#include <QApplication>
#include "test.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Test networkTest;
	QTest::qExec(&networkTest);

	MainWindow w;
	w.show();

	return a.exec();
}
