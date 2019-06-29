#include "wait_list.h"

wait_list::wait_list() {
    elem = new int [10];
    init = 10;
    n = 0;
}

wait_list::wait_list(int kol) {
    elem = new int [kol];
    init = kol;
    n = 0;
}

/*wait_list::wait_list(const wait_list &l) {
    this->init = l.init;
    this->elem = new int [l.init];
    for (int i = 0; i < l.init; i++) {
        this->elem[i] = l.elem[i];
    }
}*/

wait_list::~wait_list() {
    delete [] elem;
}

bool wait_list::is_empty() {
    if (0 == n) {
        return true;
    } else {
        return false;
    }
}

void wait_list::add(int el) {
    int i = 0;
    while (i < n && elem[i] != el) {
        i++;
    }
    if (i == n) {
        elem[i] = el;
        n++;
    }
}

int wait_list::pop() {
    int buf = elem[0];
    for (int i = 1; i < n; i++) {
        elem[i - 1] = elem[i];
    }
    n--;
    return buf;
}

void wait_list::del(int el) {
    int i = 0;
    while (i < n && elem[i] != el) {
        i++;
    }
    if (i != n) {
        n--;
        for (; i < n; i++) {
            elem[i] = elem[i + 1];
        }
    }
}




