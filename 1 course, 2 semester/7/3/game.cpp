#include "game.h"
#include <string.h>

Game::Game(int height, int width, int row) {
	fieldWidth = width;
	fieldHeight = height;
	winningRow = row;
	moveCount = 0;

	field = new int*[height];
	for (int i = 0; i < height; i++) {
		field[i] = new int[width];
		memset(field[i], noPlayer, width * sizeof(int));
	}
}

Game::~Game() {
	for (int i = 0; i < fieldHeight; i++)
		delete[] field[i];
	delete[] field;
}

int Game::getWinner() {

	for (int i = 0; i < fieldHeight; i++)
		for (int j = 0; j < fieldWidth; j++) {
			if (field[i][j] == noPlayer)
				continue;

			///Checking vertical line
			bool flag = false;
			if (i + winningRow <= fieldHeight) {
				for (int k = i + 1; k < i + winningRow; k++)
					if (field[k][j] != field[i][j]) {
						flag = true;
						break;
					}
				if (!flag) {
					isEnded = true;
					return field[i][j];
				}
			}

			///Checking horisontal line
			flag = false;
			if (j + winningRow <= fieldWidth) {
				for (int k = j + 1; k < j + winningRow; k++)
					if (field[i][k] != field[i][j]) {
						flag = true;
						break;
					}
				if (!flag) {
					isEnded = true;
					return field[i][j];
				}
			}

			///Checking increasing diagonal
			flag = false;
			if (i + winningRow <= fieldHeight && j + winningRow <= fieldWidth) {
				for (int k = 1; k < winningRow; k++)
					if (field[i + k][j + k] != field[i][j]) {
						flag = true;
						break;
					}
				if (!flag) {
					isEnded = true;
					return field[i][j];
				}
			}

			///Checking decreasing diagonal
			flag = false;
			if (i + winningRow <= fieldHeight && j - winningRow + 1 >= 0) {
				for (int k = 1; k < winningRow; k++)
					if (field[i + k][j - k] != field[i][j]) {
						flag = true;
						break;
					}
				if (!flag) {
					isEnded = true;
					return field[i][j];
				}
			}
		}

	if (moveCount == fieldHeight * fieldWidth)
		return draw;
	else
		return noPlayer;

}
