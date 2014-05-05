#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	ui->mainLayout->addLayout(ui->settingsLayout, 0, 0, 1, 5);
	ui->sizeSpinBox->setValue(2);
	connect(ui->newGameButton, SIGNAL(clicked()), this, SLOT(newGame()));

	currentGame = nullptr;
}

MainWindow::~MainWindow()
{
	delete ui;
	delete fieldMapper;
	delete coordinates;
	delete currentGame;
}

void MainWindow::newGame() {

	ui->statusText->setText("Game begins!");

	///Erasing previous game
	if (currentGame != nullptr) {

		for (int i = 0; i < currentGame->fieldSize; i++)
			for (int j = 0; j < currentGame->fieldSize; j++)
				delete ui->buttonLayout->itemAtPosition(i, j)->widget();

		delete fieldMapper;
		delete coordinates;
		delete currentGame;
	}

	currentGame = new Game(ui->sizeSpinBox->value());
	ui->mainLayout->addLayout(ui->buttonLayout, 1, 0, currentGame->fieldSize, currentGame->fieldSize);


	///Creating game field
	fieldMapper = new QSignalMapper;
	connect(fieldMapper, SIGNAL(mapped(QWidget*)), this, SLOT(gameMove(QWidget*)));

	coordinates = new QMap<QWidget*, std::pair<int, int>>;

	for (int i = 0; i < currentGame->fieldSize; i++)
		for (int j = 0; j < currentGame->fieldSize; j++) {
			QPushButton *newButton = new QPushButton;
			newButton->setText(" ");
			ui->buttonLayout->addWidget(newButton, i, j);
			connect(newButton, SIGNAL(clicked()), fieldMapper, SLOT(map()));
			fieldMapper->setMapping(newButton, newButton);
			coordinates->insert(newButton, std::make_pair(i, j));
		}
}

void MainWindow::gameMove(QWidget* cell) {

	GameProcess::gameMove(currentGame, coordinates, cell);

	if (currentGame->isEnded())
		ui->statusText->setText("You won!");
}
