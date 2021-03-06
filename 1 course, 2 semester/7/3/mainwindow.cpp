#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	ui->mainLayout->addLayout(ui->settingsLayout, 0, 0, 1, 5);
	ui->widthSpinBox->setValue(3);
	ui->heightSpinBox->setValue(3);
	ui->rulesSpinBox->setValue(3);
	connect(ui->newGameButton, SIGNAL(clicked()), this, SLOT(newGame()));

	connect(ui->rulesSpinBox, SIGNAL(valueChanged(int)), this, SLOT(correctRules()));
	connect(ui->heightSpinBox, SIGNAL(valueChanged(int)), this, SLOT(correctRules()));
	connect(ui->widthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(correctRules()));


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

		for (int i = 0; i < currentGame->fieldHeight; i++)
			for (int j = 0; j < currentGame->fieldWidth; j++)
				delete ui->buttonLayout->itemAtPosition(i, j)->widget();

		delete fieldMapper;
		delete coordinates;
		delete currentGame;
	}

	currentGame = new Game(ui->heightSpinBox->value(), ui->widthSpinBox->value(), ui->rulesSpinBox->value());
	ui->mainLayout->addLayout(ui->buttonLayout, 1, 0, currentGame->fieldHeight, currentGame->fieldWidth);


	///Creating game field
	fieldMapper = new QSignalMapper;
	connect(fieldMapper, SIGNAL(mapped(QWidget*)), this, SLOT(gameMove(QWidget*)));

	coordinates = new QMap<QWidget*, std::pair<int, int>>;

	for (int i = 0; i < currentGame->fieldHeight; i++)
		for (int j = 0; j < currentGame->fieldWidth; j++) {
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

	int winner = currentGame->getWinner();
	if (winner != Game::noPlayer) {
		if (winner == Game::firstPlayer)
			ui->statusText->setText("Tic win!");
		else if (winner == Game::secondPlayer)
			ui->statusText->setText("Toe win!");
		else
			ui->statusText->setText("Draw!");
	}

}

void MainWindow::correctRules() {

	if (ui->rulesSpinBox->value() > std::min(ui->heightSpinBox->value(), ui->widthSpinBox->value()))
		ui->rulesSpinBox->setValue(std::min(ui->heightSpinBox->value(), ui->widthSpinBox->value()));
}
