#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSignalMapper>
#include <QPushButton>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	ui->gridLayout->addWidget(ui->text, 1, 1, 1, 3);

	QPushButton *clearButton = new QPushButton("C");
	ui->gridLayout->addWidget(clearButton, 1, 4);
	connect(clearButton, SIGNAL(clicked()), this, SLOT(clearButtonClicked()));

	QPushButton *equalButton = new QPushButton("=");
	ui->gridLayout->addWidget(equalButton, 5, 3);
	connect(equalButton, SIGNAL(clicked()), this, SLOT(equalButtonClicked()));

	QPushButton *pointButton = new QPushButton(".");
	ui->gridLayout->addWidget(pointButton, 5, 2);
	connect(pointButton, SIGNAL(clicked()), this, SLOT(pointButtonClicked()));

	///Making signals for operations
	QSignalMapper *operationMapper = new QSignalMapper;
	connect(operationMapper, SIGNAL(mapped(const QString &)), this, SLOT(operationButtonClicked(const QString &)));

	for (int i = 0; i < 4; i++) {
		QString *operation = new QString;

		if (i == 0)
			operation[0] = '+';
		else if (i == 1)
			operation[0] = '-';
		else if (i == 2)
			operation[0] = '*';
		else if (i == 3)
			operation[0] = '/';

		QPushButton *newOperationButton = new QPushButton(*operation);
		ui->gridLayout->addWidget(newOperationButton, i + 2, 4);
		connect(newOperationButton, SIGNAL(clicked()), operationMapper, SLOT(map()));
		operationMapper->setMapping(newOperationButton, *operation);
	}

	///Making signals for digits
	QSignalMapper *digitMapper = new QSignalMapper;
	connect(digitMapper, SIGNAL(mapped(const QString &)), this, SLOT(digitButtonClicked(const QString &)));

	for (int i = 0; i < 10; i++) {
		QPushButton *newDigitButton = new QPushButton(QString::number(i));
		if (i == 0)
			ui->gridLayout->addWidget(newDigitButton, 5, 1);
		else {
			int row = 4 - ((i - 1) / 3);
			int column = ((i - 1) % 3) + 1;
			ui->gridLayout->addWidget(newDigitButton, row, column);
		}
		connect(newDigitButton, SIGNAL(clicked()), digitMapper, SLOT(map()));
		digitMapper->setMapping(newDigitButton, QString::number(i));
	}

}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::equalButtonClicked() {
	if (calc.state == secondNumberInt || calc.state == secondNumberFraction) {
		if (calc.isAnswerCorrect()) {
			double answer = calc.calculateAnswer();
			ui->text->setText(QString::number(answer));
		} else {
			ui->text->setText("ERROR");
		}
		calc.getReady();
	}
}

void MainWindow::pointButtonClicked() {
	if (calc.state == firstNumberInt || calc.state == secondNumberInt) {
		calc.addPoint();
		ui->text->setText(calc.currentNumber());
	}
}

void MainWindow::operationButtonClicked(const QString &operation) {
	if (calc.state == firstNumberInt || calc.state == firstNumberFraction || calc.state == mathOperation || calc.state == showAnswer) {
		calc.addOperation(operation);
	} else if (calc.state == secondNumberInt || calc.state == secondNumberFraction) {
		equalButtonClicked();
		if (ui->text->text() != "ERROR")
			calc.addOperation(operation);
	}
}

void MainWindow::digitButtonClicked(const QString &digit) {
	calc.addDigit(digit);
	ui->text->setText(calc.currentNumber());
}

void MainWindow::clearButtonClicked() {
	this->calc.clear();
	ui->text->setText(calc.currentNumber());
}
