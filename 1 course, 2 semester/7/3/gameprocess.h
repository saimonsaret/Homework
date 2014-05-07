#pragma once
#include "ui_mainwindow.h"
#include "game.h"
#include <QMap>

class GameProcess {
	public:
		static void gameMove(Game *currentGame, QMap<QWidget*, std::pair<int, int>> *coordinates, QWidget *cell);
};
