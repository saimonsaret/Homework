#pragma once
#include "ui_mainwindow.h"
#include "game.h"
#include <chrono>
#include <thread>
#include <QMap>

class GameProcess {
	public:
		static void gameMove(Game *currentGame, QMap<QWidget*, std::pair<int, int> > *coordinates, QWidget *cell) {

			if (currentGame->isEnded())
				return;

			std::pair<int, int> coord = coordinates->value(cell);
			QPushButton *button = dynamic_cast<QPushButton*>(cell);

			///Verifying if move is valid
			if (currentGame->field[coord.first][coord.second] == Game::inGame) {

				if (currentGame->moveCount % 2 == 0) {

					currentGame->chosenCell = std::make_pair(coord.first, coord.second);
					currentGame->chosenButton = button;
					currentGame->field[coord.first][coord.second] = Game::retired;
					button->setText(QString::number(currentGame->fieldValues[coord.first][coord.second]));

				} else {

					std::pair<int, int> chosenCell = currentGame->chosenCell;

					button->setText(QString::number(currentGame->fieldValues[coord.first][coord.second]));

					if (currentGame->fieldValues[coord.first][coord.second] == currentGame->fieldValues[chosenCell.first][chosenCell.second]) {
						currentGame->field[coord.first][coord.second] = Game::retired;
						currentGame->chosenButton->setEnabled(false);
						button->setEnabled(false);
					} else {
						currentGame->chosenButton->setText(" ");
						button->setText(" ");
						currentGame->field[chosenCell.first][chosenCell.second] = Game::inGame;
						currentGame->moveCount -= 2;
					}
					currentGame->chosenCell = std::make_pair(-1, -1);
					currentGame->chosenButton = nullptr;
				}
				currentGame->moveCount++;
			}
		}
};
