#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "formcreator.h"
#include <QTextEdit>
#include <fstream>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(loadForm()));

	ui->statusLineEdit->setText("Waiting for command...");
}

MainWindow::~MainWindow()
{
	delete ui;
}

bool exists(const std::string &filename) {
	return std::ifstream(filename) != nullptr;
}


void MainWindow::loadForm() {

	deleteForm(mainLayout);

	if (!exists(ui->filenameLineEdit->text().toStdString())) {
		ui->statusLineEdit->setText("File " + ui->filenameLineEdit->text() + " does not exists");
		return;
	}

	mainLayout = new QGridLayout;

	QXmlSimpleReader *parser = new QXmlSimpleReader();
	XmlSimpleContentHandler *handler = new XmlSimpleContentHandler();

	ui->statusLineEdit->setText("Loading...");

	parser->setContentHandler(handler);

	if (parser->parse(new QXmlInputSource(new QFile(ui->filenameLineEdit->text())))) {
		try {
			createForm(handler->widgetStruct);
		} catch (FormCreationError &error) {
			ui->statusLineEdit->setText(error.errorText);
			delete parser;
			delete handler;
			return;
		}
		ui->gridLayout->addLayout(mainLayout, 2, 0);
		ui->statusLineEdit->setText("Loaded successfully!");
	} else {
		ui->statusLineEdit->setText("Error occured while parsing your file");
	}

	delete parser;
	delete handler;
}

void MainWindow::createForm(WidgetTree *tree) {

	FormCreator creator;
	try {
		creator.createForm(tree->ui->children->at(0), mainLayout);
	} catch (FormCreationError &error) {
		throw error;
	}
}

void MainWindow::deleteForm(QLayout *layout) {

	if (layout == nullptr)
		return;

	///Deleting all of widgets and sublayouts of current layout
	QLayoutItem *object;
	while (object = layout->takeAt(0)) {
		if (object->layout() != nullptr)
			deleteForm(object->layout());
		else if (object->widget() != nullptr)
			delete object->widget();
	}
	delete layout;
}
