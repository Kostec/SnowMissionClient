#ifndef CLIENTS_MODEL_H
#define CLIENTS_MODEL_H

#include <QObject>
#include <QPointF>

enum TypeClient {
    Truck = 1,
    Excavator,
    Rotary_loader,
    Brush_machine,
    Reagent_brush_machine
};

enum Unit_status
{
    UnActive = 0,
    Working,
    Moving
};

class ClientData : public QObject
{
    Q_OBJECT
public:
    explicit ClientData(QObject *parent = nullptr, TypeClient _TypeClient = TypeClient::Truck);
    float get_speed();
    QPointF get_position();
    float get_performance();
    uint get_my_type();
    float get_power();
//    void set_max_speed(float newSpeed);
    void set_performance(float newPerformance);
    void set_position_x(float x_pos);
    void set_position_y(float y_pos);
    void set_my_status(uint status_work);
    uint get_status();
    uint get_work_id();

    float longituge; //долгота
    float lalittude; // широта

    int randomBetween(int low, int high);
private:

    QPointF my_position= QPointF(0,0);

    float my_performance = 1.0;

    uint status:8; //статус работы
    uint my_type:8;
    uint work_id:16;

    float velosity = 30.0; //скорость


    float power; //запас топлива

public slots:

signals:

};

#endif // CLIENTS_MODEL_H
