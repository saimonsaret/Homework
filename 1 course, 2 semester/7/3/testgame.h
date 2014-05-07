#include <QObject>
#include <QTest>
#include "game.h"

class TestGame : public QObject {
	Q_OBJECT

	public:
		explicit TestGame(QObject *parent = 0) : QObject(parent) {}
	private slots:
		void init() {
			currentGame = new Game(3, 3, 3);
		}
		void cleanup() {
			delete currentGame;
		}
		void testGameEnd() {
			for (int i = 0; i < currentGame->fieldHeight; i++)
				for (int j = 0; j < currentGame->fieldWidth; j++)
					if (i == j)
						currentGame->field[i][j] = Game::firstPlayer;
					else
						currentGame->field[i][j] = Game::secondPlayer;
			int winner = currentGame->getWinner();
			QVERIFY(currentGame->isEnded);
			QCOMPARE(winner, 1);
		}

	private:
		Game *currentGame;
};
