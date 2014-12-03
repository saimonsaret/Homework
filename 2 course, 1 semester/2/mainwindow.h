#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "computer.h"

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
	void updateComputers();

private:
	void initializeUI();
	void updateUI();
	Ui::MainWindow *ui;
	QLabel *turnLabel;
	QLabel **illnessLabels;
	Computer** comps;
	QTimer *updateTimer;
	int n = 0;
	int turn = 0;
};

#endif // MAINWINDOW_H
