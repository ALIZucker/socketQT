#include "mainwindow.h"

#include <QApplication>
#include "server.h"
#include "client.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Server s;
    s.startSearver();

    Client c;
    c.connectToServer();
    return a.exec();
}
