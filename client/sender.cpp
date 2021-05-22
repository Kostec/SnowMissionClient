#include "sender.h"

#include <QBuffer>

sendPack::sendPack(ClientData* client)
{
    {
        client_data = client;

        socket = new QTcpSocket();
        timer_connect = new QTimer();
        timer_send = new QTimer();
        timer_send->setInterval(10000);
        timer_connect->setInterval(100);

        socket->connectToHost(QHostAddress("10.13.16.250"), 50000, QIODevice::ReadWrite);
        timer_connect->start();
        connect(timer_send, SIGNAL(timeout()), this, SLOT(send_package()));
        connect(timer_connect, SIGNAL(timeout()), this, SLOT(connecting()));
    }
}

void sendPack::connecting()
{
    if (socket->state() != QAbstractSocket::ConnectingState)
    {
        if(timer_send->isActive()) timer_send->stop();
        if(!(timer_connect->isActive())) timer_connect->start();
        qDebug() << "Попытка подключения";
        socket->connectToHost(QHostAddress("10.13.16.250"), 50000, QIODevice::ReadWrite);

    }
    else if ( socket->state() != QAbstractSocket::ConnectedState)
    {
        qDebug() << "Произошло подключение";
        send_package_type();
        if(!(timer_send->isActive())) timer_send->start();
        if(timer_connect->isActive()) timer_connect->stop();
    }
}

void sendPack::send_package_type()
{
    QByteArray data;
    uint type = Packet_id::Type;
    int size = sizeof (client_data->get_my_type());

    data.append(Start_SIGNATURE);

    char pack_id[4];
    memset(pack_id,0,4);
    memcpy(&pack_id,&type,sizeof(quint16));

    data.append(pack_id);

    char _size[4];
    memset(_size,0,4);
    memcpy(&_size,&size,sizeof(quint16));

    data.append(_size);

    data.append(client_data->get_my_type());
    qDebug() << "sendPack::send_package_type()" << size << "DATA: " << data;
    socket->write(data);
}

void sendPack::send_package()
{
    if (socket->state() == QAbstractSocket::ClosingState) {
        timer_send->stop();
        timer_connect->start();
        qDebug() << "sendPack::send_package() socket close";
    }
    else
    {
        if(client_data->get_work_id() == 0)
        {
            client_data->set_my_status(0);
        }
        QByteArray data;

        char _size[4];
        memset(_size,0,4);
        memcpy(&_size,r.bytes(),sizeof(quint16));

        int size = sizeof (client_data->get_status()) + sizeof (client_data->get_work_id()) + sizeof(client_data->get_speed()) + sizeof (client_data->longituge)+ sizeof(client_data->lalittude) + sizeof(client_data->get_power());
        qDebug() << "sendPack::send_package " << size;

        data.append(Start_SIGNATURE);
        data.append(Packet_id::Telemetry);
        data.append(size);

        data.append(client_data->get_status());
        data.append(client_data->get_work_id());

        data.append(client_data->get_speed());
        data.append(client_data->longituge);
        data.append(client_data->lalittude);
        data.append(client_data->get_power());
        socket->write(data);
    }
}
