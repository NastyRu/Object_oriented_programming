#include "doors.h"

doors::doors() {
    dstate = close;
    connect(this, SIGNAL(openned()), this, SLOT(opening_doors()));
    connect(this, SIGNAL(closed()), this, SLOT(closing_doors()));
}

void doors::label(QLabel *state_doors) {
    this->state_doors = state_doors;
}

bool doors::is_open() {
    if (dstate == close) {
        return false;
    } else {
        return true;
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
        this->close_doors();
    }
}

void doors::opening_doors() {
    if (!is_open()) {
        dstate = opening;
        this->open_doors();
    }
}
