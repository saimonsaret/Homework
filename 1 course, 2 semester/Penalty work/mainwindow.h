#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "xmlsimplecontenthandler.h"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

	private slots:
		void loadForm();

	private:
		void createForm(WidgetTree *tree);
		void deleteForm(QLayout *layout);
		Ui::MainWindow *ui;
		QGridLayout *mainLayout = nullptr;
};

#endif // MAINWINDOW_H
