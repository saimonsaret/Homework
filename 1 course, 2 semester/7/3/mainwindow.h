#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "game.h"
#include "qsignalmapper.h"
#include <QMap>
#include "ui_mainwindow.h"

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
		void newGame();
		void gameMove(QWidget *cell);
		void correctRules();

	private:
		Ui::MainWindow *ui;
		Game *currentGame;
		QSignalMapper *fieldMapper;
		QMap<QWidget*, std::pair<int, int>> *coordinates;
};

#endif // MAINWINDOW_H
