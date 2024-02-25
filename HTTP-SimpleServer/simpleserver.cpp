#include "simpleserver.h"

SimpleServer::SimpleServer(QObject *parent) :
    QTcpServer(parent)
{
    if(listen(QHostAddress::Any, 80)){
        qDebug() << "Read...";


    } else {
        qDebug() << "Error while starting" << errorString();
    }
}

void SimpleServer::incomingConnection(int handle)
{
    QTcpSocket *socket = new QTcpSocket();
    socket->setSocketDescriptor(handle);

    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(socket, SIGNAL(disconected()), this, SLOT(onDisconnected()));
}

void SimpleServer::onReadyRead()
{
    // клиент, который послал сигнал
    QTcpSocket *socket = (QTcpSocket*)sender();
    qDebug() << socket->readAll();

    QString response = "HTTP/1.1 200 OK\r\n\r\n%1";
    // Отсылаем данные
    socket->write(response.arg(QDateTime::currentDateTime().toString()).toUtf8());
    socket->disconnectFromHost();
}

void SimpleServer::onDisconnected()
{
    QTcpSocket *socket = (QTcpSocket*)sender();
    socket->close();
    socket->deleteLater();
}
