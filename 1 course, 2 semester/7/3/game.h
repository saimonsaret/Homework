#pragma once

class Game {
	public:

		Game(int height, int width, int row);
		~Game();

		enum players {
			noPlayer = 0,
			firstPlayer = 1,
			secondPlayer = 2,
			draw = 3
		};

		int getWinner();

		int fieldWidth;
		int fieldHeight;
		int moveCount;
		int winningRow;
		int **field;
		bool isEnded = false;
};
