#include "button.h"

button::button() {
    bstate = reseted;
    connect(this, SIGNAL(press_btn()), this, SLOT(press()));
    connect(this, SIGNAL(reset_btn()), this, SLOT(reset()));
}

void button::set_floor(int f) {
    floor = f;
}

void button::set_btn(QPushButton *btn) {
    this->btn = btn;
}

void button::press() {
    bstate = pressed;
    btn->setStyleSheet("color: red");
}

void button::reset() {
    bstate = reseted;
    btn->setStyleSheet("color: white");
}

bool button::is_pressed() {
    if (pressed == bstate) {
        return true;
    } else {
        return false;
    }
}
