#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <cstdio>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	freopen("config.txt", "r", stdin);
	std::cin >> n;

	comps = new Computer*[n];
	Randomizer *randomizer = new TrueRandomizer;
	for (int i = 0; i < n; i++) {
		int isIll = 0;
		double chance = 0;
		std::cin >> isIll >> chance;
		comps[i] = new Computer(isIll, chance, randomizer);
	}

	for (int i = 0; i < n; i++) {
		QSet<Computer*> *set = new QSet<Computer*>;
		for (int j = 0; j < n; j++) {
			int edge = 0;
			std::cin >> edge;
			if (edge)
				set->insert(comps[j]);
		}
		comps[i]->setAdjacentComputers(set);
	}
	updateTimer = new QTimer;
	connect(updateTimer, SIGNAL(timeout()), this, SLOT(updateComputers()));
	initializeUI();
}

MainWindow::~MainWindow()
{
	for (int i = 0; i < n; i++) {
		delete comps[i];
		delete illnessLabels[i];
	}
	delete[] comps;
	delete[] illnessLabels;
	delete ui;
}

void MainWindow::updateComputers() {
	bool *illComps = new bool[n];
	for (int i = 0; i < n; i++)
		illComps[i] = comps[i]->isIll();
	for (int i = 0; i < n; i++)
		if (illComps[i])
			comps[i]->makeTurn();
	updateUI();
}

void MainWindow::initializeUI() {
	turnLabel = new QLabel("Turn 0");
	ui->mainLayout->addWidget(turnLabel);
	illnessLabels = new QLabel*[n];
	for (int i = 0; i < n; i++) {
		QHBoxLayout *layout = new QHBoxLayout;
		layout->addWidget(new QLabel(QString::number(i + 1)));
		illnessLabels[i] = new QLabel("Not infected");
		layout->addWidget(illnessLabels[i]);
		ui->mainLayout->addLayout(layout);
	}
	updateUI();
}

void MainWindow::updateUI() {
	turn++;
	turnLabel->setText("Turn " + QString::number(turn));
	for (int i = 0; i < n; i++)
		if (comps[i]->isIll())
			illnessLabels[i]->setText("Infected!");
	updateTimer->start(timerDelay);
}
