#ifndef LIFT_H
#define LIFT_H

#include <QObject>
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QApplication>
#include <QTime>
#include "doors.h"
#include "error.h"
#include "button.h"
#include "wait_list.h"

#define NUM_FLOORS 10

class lift : public QObject {
    Q_OBJECT
    enum lift_state {
        up,
        down,
        wait_open,
        wait_close,
    };

public:
    lift();
    void labels(QLabel *state_floor, QLabel *state_lift, QLabel *state_doors);
    void buttons(int n, ...);
    void get_floor(int f);
    void pause(int msec);

private:
    QLabel *state_floor;
    QLabel *state_lift;
    int cur_floor;
    int next_floor;
    int begin_floor = 1;
    int end_floor = 10;
    wait_list queue;
    doors *my_doors;
    button *my_button[NUM_FLOORS];
    lift_state lstate;
    void go_to_floor(int f);

public slots:
    void go_up();
    void go_down();
    void go_wait_open();
    void go_wait_close();

signals:
    void went_up();
    void went_down();
    void opened_doors();
    void closed_doors();
    void arrived();
};

#endif // LIFT_H
