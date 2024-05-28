#include "client.h"

#include "QDebug"


Client::Client(QObject  *parent):QObject(parent)
{
        socket =new QTcpSocket(this);

        connect(socket,&QTcpSocket::connected,this,&Client::onConnected);
        connect(socket,&QTcpSocket::readyRead,this,&Client::onReadyRead);
}

void Client::connectToServer()
{
    socket->connectToHost("127.0.0.1",1234);

    if (!socket->waitForConnected(3000)) {
           qDebug() << "Connection failed!";
    }
}

void Client::onConnected()
{
    qDebug() << "Connected to server!";
    socket->write("HELLO,SERVER");

}

void Client::onReadyRead()
{
    QByteArray data = socket->readAll();
    qDebug() << "Data received from server:" << data;

}
