#ifndef DRAW_H
#define DRAW_H

#include "base_draw.h"
#include <QPainter>
#include "points.h"

class DrawQt : public Base_draw
{
public:
    DrawQt(QPainter &pa) : p(pa) {}
    ~DrawQt() {}

    void drawline(Point_3d begin, Point_3d end) override;

private:
    QPainter &p;
};

#endif // DRAW_H
