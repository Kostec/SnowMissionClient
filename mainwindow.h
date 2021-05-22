#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qmenubar.h>
#include <client/sender.h>
#include "client_view.h"
#include "client/sender.h"
#include "listener_task.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QMenuBar main_menu_bar;
    QMenu* settings_client;
    ClientWidget_Settings* clientSettings;
    sendPack* send_p = nullptr;
    ClientData* client_data = nullptr;
    ListenerTask* listener_task = nullptr;

//    QGraphicsScene *graphics_scene = nullptr;

private slots:
    void open_settings();

protected:
    void closeEvent(QCloseEvent *event);
};
#endif // MAINWINDOW_H
