#include "clients_model.h"
#include <QDebug>

ClientData::ClientData(QObject *parent, TypeClient _TypeClient) : QObject(parent)
{
    my_type = _TypeClient;
    longituge = randomBetween(0,2000);
    lalittude = randomBetween(0,2000);
}

int ClientData::randomBetween(int low, int high)
{
return (qrand() % ((high + 1) - low) + low);
}

float ClientData::get_speed()
{
    return velosity;
}

QPointF ClientData::get_position()
{
    return my_position;
}

float ClientData::get_performance()
{
    return my_performance;
}

uint ClientData::get_my_type()
{
    return my_type;
}

float ClientData::get_power()
{
    return power;
}

void ClientData::set_position_x(float x_pos)
{
    my_position.setX(x_pos);
}

void ClientData::set_position_y(float y_pos)
{
    my_position.setY(y_pos);
}

void ClientData::set_my_status(uint status_work)
{
    status = status_work;
}

uint ClientData::get_status()
{
    return status;
}

uint ClientData::get_work_id()
{
    return work_id;
}

void ClientData::set_performance(float newPerformance)
{
    my_performance = newPerformance;
}


