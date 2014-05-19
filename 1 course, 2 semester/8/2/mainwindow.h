#include <QMainWindow>
#include <QObject>
#include <QtNetwork>
#include <QtWebKit>
#include <QWebView>
#include <QWebFrame>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

	private slots:
		void loadMainWebpage();
		void findFirstQuote();
		void loadCurrentWebpage();
		void parseQuote();
		void nextQuote();
		void prevQuote();
		void rulez();
		void sux();
		void bayan();
		void gotoQuote();

	private:

		struct Quote {

			Quote(QWebView *webpage) {
				id = webpage->page()->mainFrame()->findFirstElement("a[class=id]");
				rating = webpage->page()->mainFrame()->findFirstElement("span[class=rating]");
				text = webpage->page()->mainFrame()->findFirstElement("div[class=text]");
			}

			QWebElement text;
			QWebElement id;
			QWebElement rating;
		};

		void enableWidgets(bool value);
		void showQuote(const Quote &currentQuote);
		Ui::MainWindow *ui;

		int currentID;
		int maxID;
		QWebView *currentWebpage;
};
