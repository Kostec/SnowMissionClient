#include "client_view.h"

ClientWidget_Settings::ClientWidget_Settings(QObject *parent, ClientData* _client_data)
{
    client_data = _client_data;

    icon_types.insert(0, QIcon(":/images/Excavator.png"));
    qDebug() << icon_types.first();
    QIcon ic = icon_types.first();
    QPixmap px = ic.pixmap(100,100);

    lbl_test_icon.setPixmap(px);
    type_edit.setEnabled(false);
    speed_label.setText("Скорость: ");
    performance_label.setText("Производительность: ");
    position_label_x.setText("Позиция(x): ");
    position_label_y.setText("Позиция(y): ");
    type_label.setText("Тип: ");

    main_layout.addWidget(&speed_label, 0, 0);
    main_layout.addWidget(&performance_label, 1, 0);

    main_layout.addWidget(&position_label_x,2,0);
    main_layout.addWidget(&x_position_edit, 2, 1);
    main_layout.addWidget(&position_label_y,3,0);
    main_layout.addWidget(&y_position_edit, 3, 1);
    main_layout.addLayout(&position_layout, 2, 0);
    main_layout.addWidget(&type_label, 4, 0);

//    position_layout.addWidget(&speed_label);
//    position_layout.addWidget(&performance_label);

//    position_layout.addWidget(&position_label_x);
//    position_layout.addWidget(&x_position_edit);
//    position_layout.addWidget(&position_label_y);
//    position_layout.addWidget(&y_position_edit);
//    position_layout.addLayout(&position_layout);
//    position_layout.addWidget(&type_label);
//    position_layout.addWidget(&speed_edit);
//    position_layout.addWidget(&performance_edit);
//    position_layout.addWidget(&type_edit);
//    main_layout.addLayout(position)
//    main_layout.setRowStretch(2, 3);
//    position_layout.addWidget(&lbl_test_icon, 2, 2);

//    main_layout.addWidget(&speed_edit, 0, 1);
//    main_layout.addWidget(&performance_edit, 1, 1);
    main_layout.addWidget(&type_edit, 4, 1);

    speed_edit.setText(QString::number(client_data->get_speed()));
    x_position_edit.setText(QString::number(client_data->get_position().x()));
    y_position_edit.setText(QString::number(client_data->get_position().y()));
    performance_edit.setText(QString::number(client_data->get_performance()));
    type_edit.setText(QString::number(client_data->get_my_type()));


    connect(&speed_edit, SIGNAL(editingFinished()), this, SLOT(speed_edit_finished()));
    connect(&performance_edit, SIGNAL(editingFinished()), this, SLOT(performance_edit_finished()));
    connect(&x_position_edit, SIGNAL(editingFinished()), this, SLOT(x_position_edit_finished()));
    connect(&y_position_edit, SIGNAL(editingFinished()), this, SLOT(y_position_edit_finished()));

    this->setLayout(&main_layout);
    this->setFocus();
}

void ClientWidget_Settings::speed_edit_finished()
{
    try {
//        client_data->set set_max_speed(speed_edit.text().toFloat());
    }  catch (QException ex) {

    }
}

void ClientWidget_Settings::performance_edit_finished()
{
    try {
        client_data->set_performance(performance_edit.text().toFloat());

    }  catch (QException ex) {

    }
}

void ClientWidget_Settings::x_position_edit_finished()
{
    try {
        client_data->set_position_x(x_position_edit.text().toFloat());

    }  catch (QException ex) {

    }
}

void ClientWidget_Settings::y_position_edit_finished()
{
    try {
        client_data->set_position_y(speed_edit.text().toFloat());

    }  catch (QException ex) {

    }
}
