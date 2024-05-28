#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>


class Client : public QObject {

    Q_OBJECT

public:
    explicit Client(QObject *parent = nullptr);
    void connectToServer();

private slots:
    void onConnected();
    void onReadyRead();

private:
    QTcpSocket *socket;
};

#endif // CLIENT_H
