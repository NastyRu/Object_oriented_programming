#include "draw.h"

void DrawQt::drawline(Point_3d begin, Point_3d end) {
    Point_2d p1 = begin;
    Point_2d p2 = end;
    p.drawLine(p1.get_x(), p1.get_y(), p2.get_x(), p2.get_y());
}
