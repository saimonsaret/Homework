#pragma once
#include <stdlib.h>
#include "ui_mainwindow.h"

class Game {
	public:

		Game(int size) {
			fieldSize = size;
			moveCount = 0;

			field = new int*[size];
			for (int i = 0; i < size; i++) {
				field[i] = new int[size];
				memset(field[i], inGame, size * sizeof(int));
			}


			int countOdds = 0;
			fieldValues = new int*[size];
			for (int i = 0; i < size; i++) {
				fieldValues[i] = new int[size];
				for (int j = 0; j < size; j++) {
					fieldValues[i][j] = rand() % 2;
					if (fieldValues[i][j] % 2 != 0)
						countOdds++;
				}
			}
			if (countOdds % 2 != 0)
				fieldValues[0][0] = 1 - fieldValues[0][0];
		}

		~Game() {
			for (int i = 0; i < fieldSize; i++)
				delete[] field[i];
			delete[] field;
		}

		enum cellType {
			inGame = 0,
			retired = 1
		};

		bool isEnded() {

			if (moveCount == fieldSize * fieldSize)
				return retired;
			else
				return inGame;

		}
		int fieldSize;
		int moveCount;
		int **field;
		int **fieldValues;
		std::pair<int, int> chosenCell = std::make_pair(-1, -1);
		QPushButton *chosenButton = nullptr;
};
