#include "lift.h"

void lift::pause(int msec)
{
    QTime next = QTime::currentTime().addMSecs(msec);
    while (QTime::currentTime() < next)
        QApplication::processEvents(QEventLoop::AllEvents, 100);
}

lift::lift() {
    cur_floor = 1;
    lstate = wait_open;
    queue = wait_list(NUM_FLOORS);
    my_doors = new doors;
    connect(this, SIGNAL(went_up()), this, SLOT(go_up()));
    connect(this, SIGNAL(went_down()), this, SLOT(go_down()));
    connect(this, SIGNAL(opened_doors()), this, SLOT(go_wait_open()));
    connect(this, SIGNAL(closed_doors()), this, SLOT(go_wait_close()));
    connect(this, SIGNAL(arrived()), this, SLOT(go_wait_open()));

    for (int i = 0; i < NUM_FLOORS; i++) {
        my_button[i] = new button;
    }
}

void lift::labels(QLabel *state_floor, QLabel *state_lift, QLabel *state_doors) {
    this->state_floor = state_floor;
    this->state_lift = state_lift;
    my_doors->label(state_doors);
}

void lift::buttons(int n, ...) {
    va_list va;
    va_start(va, n);
    for (int i = 0; i < n; i++) {
        QPushButton *elem = va_arg(va, QPushButton *);
        my_button[i]->set_btn(elem);
        my_button[i]->set_floor(i % NUM_FLOORS + 1);
    }
    va_end(va);
}

void lift::get_floor(int f) {
    emit my_button[f - 1]->press_btn();
    if (wait_open == lstate || wait_close == lstate) {
        next_floor = f;
        go_to_floor(f);
    } else {
        queue.add(f);
    }
}

void lift::go_to_floor(int f) {
    if (f < cur_floor) {
        emit went_down();
    } else if (f > cur_floor) {
        emit went_up();
    } else {
        emit arrived();
        emit my_button[next_floor - 1]->reset_btn();
    }
    while (!queue.is_empty()) {
        next_floor = queue.pop();
        go_to_floor(next_floor);
    }
}

void lift::go_up() {
    if (wait_open == lstate) {
        emit closed_doors();
    }

    lstate = up;
    state_lift->setText("Вверх");
    pause(200);
    cur_floor++;
    state_floor->setText(QString::number(cur_floor));

    if (cur_floor == next_floor || my_button[cur_floor - 1]->is_pressed()) {
        pause(200);
        queue.del(cur_floor);
        emit arrived();
    }

    if (cur_floor < next_floor) {
        pause(200);
        emit went_up();
    }
}

void lift::go_down() {
    if (wait_open == lstate) {
        emit closed_doors();
    }

    lstate = down;
    state_lift->setText("Вниз");
    pause(200);
    cur_floor--;
    state_floor->setText(QString::number(cur_floor));

    if (cur_floor == next_floor || my_button[cur_floor - 1]->is_pressed()) {
        pause(200);
        queue.del(cur_floor);
        emit arrived();
    }

    if (cur_floor > next_floor) {
        pause(200);
        emit went_down();
    }
}

void lift::go_wait_open() {
    lstate = wait_open;
    state_lift->setText("Стоит");
    pause(200);
    emit my_button[cur_floor - 1]->reset_btn();
    emit my_doors->opening_doors();
}

void lift::go_wait_close() {
    state_lift->setText("Стоит");
    lstate = wait_close;
    emit my_doors->closing_doors();
    pause(200);
}

