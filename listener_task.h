#ifndef LISTENERTASK_H
#define LISTENERTASK_H

#include <QObject>
#include "package_quest.h"
#include <QTcpSocket>
#include <clients_model.h>
#include <qtcpserver.h>

class ListenerTask: public QTcpServer
{
    Q_OBJECT
public:
    ListenerTask(ClientData* _client_data, QObject* parent = nullptr);

    QTcpSocket* socket = nullptr;

    QString Start_SIGNATURE = "[START]";

    ClientData* client_data = nullptr;

signals:
    void change_status_task(uint task_id);
    void change_area_clean(QVector<int>);
public slots:

    void resive_Data();

private slots:

    int readInt();

    // QTcpServer interface
protected:
    void incomingConnection(qintptr descriptor);
};

#endif // LISTENERTASK_H
