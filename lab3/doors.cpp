#include "doors.h"

doors::doors() {
    dstate = open;
    connect(this, SIGNAL(openned()), this, SLOT(opening_doors()));
    connect(this, SIGNAL(closed()), this, SLOT(closing_doors()));

    connect(&door_open_timer, SIGNAL(timeout()), this, SLOT(open_doors()));
    connect(&door_close_timer, SIGNAL(timeout()), this, SLOT(close_doors()));
}

void doors::label(QLabel *state_doors) {
    this->state_doors = state_doors;
}

bool doors::is_open() {
    if (dstate == open || dstate == opening) {
        return true;
    } else {
        return false;
    }
}

void doors::open_doors() {
    dstate = open;
    state_doors->setText("Открыты");
}

void doors::close_doors() {
    dstate = close;
    state_doors->setText("Закрыты");
}

void doors::closing_doors() {
    if (is_open()) {
        dstate = closing;
        state_doors->setText("Закрываются");
        door_close_timer.setSingleShot(true);
        door_close_timer.start(wait_time);
    }
}

void doors::opening_doors() {
    if (!is_open()) {
        dstate = opening;
        state_doors->setText("Открываются");
        door_open_timer.setSingleShot(true);
        door_open_timer.start(wait_time);
    }
}
