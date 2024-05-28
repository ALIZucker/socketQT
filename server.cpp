#include "server.h"
#include <QDebug>


Server::Server(QObject *parent):QTcpServer(parent){}

void Server::startSearver()
{
            if(!this->listen(QHostAddress::Any,1234)){
                qDebug()<<"Server could not start";
            }else {
                qDebug()<<"Server started!";
            }
}

void Server::incomingConnection(qintptr socketDescripto)
{
        socket=new QTcpSocket(this);

        if(!socket->setSocketDescriptor(socketDescripto)){
            qDebug()<<"Error socket!";
            return;
        }

        connect(socket,&QTcpSocket::readyRead,this,&Server::onReadyRead);
        connect(socket,&QTcpSocket::disconnected,this,&Server::onDisconnected);

        qDebug()<<"client connect!";

}

void Server::onReadyRead()
{
            QByteArray data=socket->readAll();
            qDebug()<<"Data received   "<<data;
            socket->write("data recive");
}

void Server::onDisconnected()
{
    qDebug() << "Client disconnected.";
       socket->deleteLater();
}




