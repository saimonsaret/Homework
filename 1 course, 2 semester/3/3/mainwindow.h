#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "calculator.h"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();
		Calculator calc;

	private slots:
		void equalButtonClicked();
		void pointButtonClicked();
		void operationButtonClicked(const QString &operation);
		void digitButtonClicked(const QString &digit);
		void clearButtonClicked();


	private:
		Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
