#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculator.h"
#include <math.h>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	ui->operation->addItem("+");
	ui->operation->addItem("-");
	ui->operation->addItem("*");
	ui->operation->addItem("/");

	connect(ui->firstNumber, SIGNAL(valueChanged(int)),
		this, SLOT(updateAnswer()));
	connect(ui->secondNumber, SIGNAL(valueChanged(int)),
		this, SLOT(updateAnswer()));
	connect(ui->operation, SIGNAL(currentTextChanged(QString)),
		this, SLOT(updateAnswer()));

}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::updateAnswer() {
	int firstNumber = ui->firstNumber->value();
	int secondNumber = ui->secondNumber->value();
	char operation = ui->operation->currentText().toStdString()[0];

	Calculator calc;

	if (!calc.isCorrect(firstNumber, secondNumber, operation)) {
		ui->answer->setText("ERROR");
		return;
	}

	double answer = calc.calculate(firstNumber, secondNumber, operation);
	if (fabs(answer - floor(answer)) < eps) {
			ui->answer->setText(QString::number((int)floor(answer)));
		} else if (fabs(answer - ceil(answer)) < eps) {
			ui->answer->setText(QString::number((int)ceil(answer)));
		} else {
			ui->answer->setText(QString::number(answer));
		}
}
