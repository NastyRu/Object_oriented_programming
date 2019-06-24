#include "positions.h"
#include <QDebug>

Position::Position(Point_3d center) {
    this->center = center;
}

Position::Position(vector<Point_3d> points) {
    double max_x, min_x, max_y, min_y, max_z, min_z;
    for (int i = 0; i < points.size(); i++) {
        if (points[i].get_x() > max_x) {
            max_x = points[i].get_x();
        }
        if (points[i].get_x() < min_x) {
            min_x = points[i].get_x();
        }
        if (points[i].get_y() > max_y) {
            max_y = points[i].get_y();
        }
        if (points[i].get_y() < min_y) {
            min_y = points[i].get_y();
        }
        if (points[i].get_z() > max_z) {
            max_z = points[i].get_z();
        }
        if (points[i].get_z() < min_z) {
            min_z = points[i].get_z();
        }
    }
    Point_3d tmp;
    tmp.set_x((min_x + max_x) / 2);
    tmp.set_y((min_y + max_y) / 2);
    tmp.set_z((min_z + max_z) / 2);
    center = tmp;
}

void Position::offset_center(int dx, int dy, int dz) {
    center.offset(dx, dy, dz);
}

Point_3d &Position::get_center() {
    return center;
}
