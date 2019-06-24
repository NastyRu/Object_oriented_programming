#ifndef POSITIONS_H
#define POSITIONS_H

#include "points.h"
#include "iterators.h"

class Position
{
public:
    Position() {}
    Position(Point_3d center);
    Position(vector<Point_3d> points);
    ~Position() {}

    void offset_center(int dx, int dy, int dz);
    Point_3d &get_center();

private:
    Point_3d center;
};

#endif // POSITIONS_H
