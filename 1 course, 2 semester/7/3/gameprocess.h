#pragma once
#include "ui_mainwindow.h"
#include "game.h"
#include <QMap>

class GameProcess {
	public:
		static void gameMove(Game *currentGame, QMap<QWidget*, std::pair<int, int>> *coordinates, QWidget *cell) {

			if (currentGame->isEnded)
				return;

			if (!coordinates->contains(cell))
				return;

			std::pair<int, int> coord = coordinates->take(cell);
			QPushButton *button = dynamic_cast<QPushButton*>(cell);

			///Verifying if move is valid
			if (currentGame->field[coord.first][coord.second] == Game::noPlayer) {
				if (currentGame->moveCount % 2 == 0) {
					button->setText("X");
					currentGame->field[coord.first][coord.second] = Game::firstPlayer;
				} else {
					button->setText("O");
					currentGame->field[coord.first][coord.second] = Game::secondPlayer;
				}
				currentGame->moveCount++;
			}
		}
};
