#ifndef CLIENT_VIEW_H
#define CLIENT_VIEW_H

#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPointF>
#include <QException>
#include <QDebug>
#include <QIcon>
#include "clients_model.h"

class ClientWidget_Settings : public QWidget
{
    Q_OBJECT
public:
    ClientWidget_Settings(QObject *parent, ClientData* client_data);

private:
    //Data
    QPointF my_position;
    float x_position;
    float y_position;
    TypeClient my_type;
    float my_speed;
    float performance;
    ClientData* client_data;
    QWidget settingsWidget;
    QLabel lbl_test_icon;
    QMap<int, QIcon> icon_types;

    //View
    QGridLayout main_layout;
    QVBoxLayout position_layout;
    QLabel speed_label;
    QLabel performance_label;
    QLabel position_label_x, position_label_y;
    QLabel type_label;

    QLineEdit speed_edit;
    QLineEdit performance_edit;
    QLineEdit position_edit;
    QLineEdit x_position_edit;
    QLineEdit y_position_edit;

    QLineEdit type_edit;

public slots:
    void speed_edit_finished();
    void performance_edit_finished();
    void x_position_edit_finished();
    void y_position_edit_finished();

};

#endif // CLIENT_VIEW_H
