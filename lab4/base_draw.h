#ifndef BASE_DRAW_H
#define BASE_DRAW_H

#include <points.h>

class Base_draw
{
public:
    Base_draw() {}
    ~Base_draw() {}

    virtual void drawline(Point_3d begin, Point_3d end) = 0;
};

#endif // BASE_DRAW_H
