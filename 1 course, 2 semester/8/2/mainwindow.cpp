#include"mainwindow.h"
#include"ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	enableWidgets(false);

	loadMainWebpage();

	connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(nextQuote()));
	connect(ui->prevButton, SIGNAL(clicked()), this, SLOT(prevQuote()));
	connect(ui->gotoButton, SIGNAL(clicked()), this, SLOT(gotoQuote()));
	connect(ui->rulezButton, SIGNAL(clicked()), this, SLOT(rulez()));
}

MainWindow::~MainWindow()
{
	delete ui;
	delete currentWebpage;
}

void MainWindow::loadMainWebpage() {
	ui->quoteText->setText("Loading...");
	currentWebpage = new QWebView;
	currentWebpage->load(QUrl("http://bash.im"));
	connect(currentWebpage, SIGNAL(loadFinished(bool)), this, SLOT(findFirstQuote()));
}

void MainWindow::findFirstQuote() {
	QWebElement firstQuoteID = currentWebpage->page()->mainFrame()->findFirstElement("a[class=id]");
	maxID = (firstQuoteID.toPlainText().mid(1)).toInt();
	currentID = maxID;
	ui->gotoLineEdit->setValidator(new QIntValidator(1, maxID));

	Quote currentQuote(currentWebpage);
	showQuote(currentQuote);

	enableWidgets(true);
}

void MainWindow::loadCurrentWebpage() {
	ui->quoteText->setText("Loading...");
	enableWidgets(false);

	delete currentWebpage;
	currentWebpage = new QWebView;
	currentWebpage->load(QUrl("http://bash.im/quote/" + QString::number(currentID)));
	connect(currentWebpage, SIGNAL(loadFinished(bool)), this, SLOT(parseQuote()));

	enableWidgets(true);
}

void MainWindow::parseQuote() {
	showQuote(Quote(currentWebpage));
}

void MainWindow::nextQuote() {
	if (currentID - 1 < 1) {
		QMessageBox::information(this, "Information", "Previous quote was the first one.");
		return;
	}

	currentID--;
	loadCurrentWebpage();
	ui->gotoLineEdit->setText(QString::number(currentID));
}

void MainWindow::prevQuote() {
	if (currentID + 1 > maxID) {
		QMessageBox::information(this, "Information", "Previous quote was the last one.");
		return;
	}

	currentID++;
	loadCurrentWebpage();
	ui->gotoLineEdit->setText(QString::number(currentID));
}

void MainWindow::rulez() {
	QNetworkRequest postRequest(QUrl("http://bash.im/quote/" + QString::number(currentID)));
	postRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
	QNetworkAccessManager *postManager = new QNetworkAccessManager(this);
	postManager->post(postRequest, "/rulez");

	loadCurrentWebpage();
	delete postManager;
}

void MainWindow::sux() {
	QNetworkRequest postRequest(QUrl("http://bash.im/quote/" + QString::number(currentID)));
	postRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
	QNetworkAccessManager *postManager = new QNetworkAccessManager(this);
	postManager->post(postRequest, "/sux");

	loadCurrentWebpage();
	delete postManager;
}
void MainWindow::bayan() {
	QNetworkRequest postRequest(QUrl("http://bash.im/quote/" + QString::number(currentID)));
	postRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
	QNetworkAccessManager *postManager = new QNetworkAccessManager(this);
	postManager->post(postRequest, "/bayan");

	loadCurrentWebpage();
	delete postManager;
}
void MainWindow::gotoQuote() {
	currentID = ui->gotoLineEdit->text().toInt();
	loadCurrentWebpage();
	ui->gotoLineEdit->setText(QString::number(currentID));
}

void MainWindow::showQuote(const Quote &currentQuote) {
	ui->ratingLineEdit->setText(QString(currentQuote.rating.toPlainText()));
	ui->quoteText->setText(QString(currentQuote.text.toPlainText()));
	ui->gotoLineEdit->setText(QString(currentQuote.id.toPlainText()).mid(1));
}

void MainWindow::enableWidgets(bool value) {
	ui->bayanButton->setEnabled(value);
	ui->gotoButton->setEnabled(value);
	ui->nextButton->setEnabled(value);
	ui->rulezButton->setEnabled(value);
	ui->prevButton->setEnabled(value);
	ui->suxButton->setEnabled(value);
	ui->gotoLineEdit->setEnabled(value);
	ui->ratingLineEdit->setEnabled(value);
}
