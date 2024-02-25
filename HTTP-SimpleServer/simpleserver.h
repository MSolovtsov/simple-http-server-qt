#pragma once

#ifndef SIMPLESERVER_H
#define SIMPLESERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QDateTime>

class SimpleServer : public QTcpServer {
    Q_OBJECT
public:
    SimpleServer(QObject *parent);

    void incomingConnection(int handle);

signals:

public slots:
    // Сигнал соединяется при получении нового пакета данных
    void onReadyRead();
    void onDisconnected();
};

#endif // SIMPLESERVER_H
