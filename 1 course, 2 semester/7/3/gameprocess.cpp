#include "gameprocess.h"

void GameProcess::gameMove(Game *currentGame, QMap<QWidget *, std::pair<int, int> > *coordinates, QWidget *cell) {

	if (currentGame->isEnded)
		return;

	if (!coordinates->contains(cell))
		return;

	///Improtant use of QMap::take; we take value from the map, and it can be never used once again
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
		button->setEnabled(false);
	}

}
