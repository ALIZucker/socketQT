#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include<QTcpSocket>

class Server :public QTcpServer
{
    Q_OBJECT

public:
    explicit Server(QObject *parnt=nullptr);
    void startSearver();

protected:
    void incomingConnection(qintptr socketDescripto) override;

private slots:
        void onReadyRead();
        void onDisconnected();
private:
        QTcpSocket *socket;
};

#endif // SERVER_H
