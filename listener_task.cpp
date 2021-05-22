#include "listener_task.h"

ListenerTask::ListenerTask(ClientData* _client_data, QObject *parent)
{
    if(!this->listen(QHostAddress::LocalHost, 5001)){
        qDebug() << "Error create";
        return;
    }

    qDebug() << tr("The server is running on\n\nIP: %1\nport: %2\n\n")
                .arg(this->serverAddress().toString()).arg(this->serverPort());
    connect(this, SIGNAL(change_status_task(uint)), _client_data, SLOT(new_task_come(uint)));
}

void ListenerTask::resive_Data()
{
    if (socket->bytesAvailable() == 0) return;
    socket->startTransaction();
    QByteArray buffer = socket->readAll();
    int index = buffer.indexOf(Start_SIGNATURE.toUtf8());

    if (index == -1) {
        qDebug() << "Начало пакета не найдено";
        socket->commitTransaction();
        return;
    }
    socket->rollbackTransaction();
    socket->startTransaction();

    socket->read(index);
    socket->commitTransaction();
    socket->startTransaction();

    socket->read(Start_SIGNATURE.size() - 1);
    //ID задачи
    int id_task = readInt();
    if(id_task == -1){
        qDebug() << "Не удалось прочитать ID задачи";
        socket->rollbackTransaction();
        return;
    }
    else emit change_status_task(id_task);
    int count_rect = readInt();
    if(count_rect == -1)
    {
        qDebug() << "Не удалось прочитать количество элементов";
        socket->rollbackTransaction();
        return;
    }
}

int ListenerTask::readInt() {
    QByteArray bytes = socket->read(sizeof(int));
    if (bytes.size() != sizeof(int)) return -1;
    return *(int*)bytes.constData();
}

void ListenerTask::incomingConnection(qintptr descriptor)
{
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(descriptor)) {
        qDebug() << "Bad socket or descriptor";
        delete socket;
        return;
    }
    addPendingConnection(socket);
    connect(socket,SIGNAL(readyRead()),SLOT(resive_Data()));
}
