#include "point.h"

int from_3d_to_2d(int par, int z) {
    return int(par + TO_3D * z);
}

int point_by_name(Point_3d point, int i) {
    switch (i) {
        case X_NAME:
            return point.x;
        case Y_NAME:
            return point.y;
        case Z_NAME:
            return point.z;
        default:
            return OK;
    }
}

void scale_point(Point_3d &p, Point_3d c, Actions act) {
    p.x = int(c.x + act.k * (p.x - c.x));
    p.y = int(c.y + act.k * (p.y - c.y));
    p.z = int(c.z + act.k * (p.z - c.z));
}

void offset_point(Point_3d &p, Actions act) {
    p.x += act.dx;
    p.y += act.dy;
    p.z += act.dz;
}

void rotate_point(Point_3d &p, Point_3d c, Actions act) {
    Point_3d t = p;
    double anx = act.anx * RAD;
    double any = act.any * RAD;
    double anz = act.anz * RAD;

    p.y = int(c.y + (t.y - c.y) * cos(anx) + (t.z - c.z) * sin(anx));
    p.z = int(c.z - (t.y - c.y) * sin(anx) + (t.z - c.z) * cos(anx));

    t = p;
    p.x = int(c.x + (t.x - c.x) * cos(any) + (t.z - c.z) * sin(any));
    p.z = int(c.z - (t.x - c.x) * sin(any) + (t.z - c.z) * cos(any));

    t = p;
    p.x = int(c.x + (t.x - c.x) * cos(anz) + (t.y - c.y) * sin(anz));
    p.y = int(c.y - (t.x - c.x) * sin(anz) + (t.y - c.y) * cos(anz));
}

int read_point(Point_3d &point, File &file) {
    if (readf(point.x, file) > 0) {
        return INCORRECT;
    }
    if (readf(point.y, file) > 0) {
        return INCORRECT;
    }
    if (readf(point.z, file) > 0) {
        return INCORRECT;
    }
    return OK;
}

void write_point(File &file, Point_3d point) {
    writef(file, point.x);
    writef(file, ' ');
    writef(file, point.y);
    writef(file, ' ');
    writef(file, point.z);
    writef(file, '\n');
}
