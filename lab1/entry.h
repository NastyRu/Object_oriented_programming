#ifndef ENTRY_H
#define ENTRY_H

#include <QPainter>

enum Act {
    off, rot, sc, ex, load, save, draw
};

struct Actions {
    int dx;
    int dy;
    int dz;
    double k;
    int anx;
    int any;
    int anz;
    const char* filename;
    QPainter *p;
};
int entry_func(const Act , Actions);

#endif // ENTRY_H
