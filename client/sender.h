#ifndef SENDER_H
#define SENDER_H

#include <QObject>
#include <QTcpSocket>
#include <QTimer>
#include <qexception.h>
#include <QHostAddress>
#include "clients_model.h"
#include "package/type_package.h"

class sendPack : public QObject
{
    Q_OBJECT
public:
    enum Packet_id
    {
        Telemetry = 1,
        Type
    };
    explicit sendPack(ClientData* client);

    QTcpSocket* socket = nullptr;
    QString Start_SIGNATURE = "[START]";

    ClientData* client_data = nullptr;

    QTimer* timer_send;
    QTimer* timer_connect;

    type_package r;

    void send_package_type();
public slots:
    void send_package();
    void connecting();
};

#endif // SENDER_H
