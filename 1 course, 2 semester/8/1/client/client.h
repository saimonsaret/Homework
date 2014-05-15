#include <QDialog>
#include <QtNetwork>
#include <QTextEdit>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QLayout>
#include <QMessageBox>

class Client : public QDialog
{
	Q_OBJECT

public:
	explicit Client(QWidget *parent = 0);

private slots:
	void sessionOpened();
	void displayError(QAbstractSocket::SocketError socketError);
	void sendMessage();
	void startRead();
	void connectToServer();
	void disconnectedFromServer();

private:
	QLabel *hostLabel;
	QLabel *portLabel;
	QComboBox *hostAdress;
	QLineEdit *portLineEdit;
	QTextEdit *chatText;
	QLineEdit *messageText;
	QLabel *statusLabel;
	QPushButton *quitButton;
	QPushButton *sendButton;
	QPushButton *connectButton;
	QTcpSocket *serverSocket;
	QNetworkSession *networkSession;
	quint16 blockSize;
};
