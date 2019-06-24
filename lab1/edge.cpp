#include "edge.h"

void draw_edge(Point_3d o, Point_3d k, Actions actions) {
    int xo = from_3d_to_2d(o.x, o.z);
    int yo = from_3d_to_2d(o.y, o.z);
    int xk = from_3d_to_2d(k.x, k.z);
    int yk = from_3d_to_2d(k.y, k.z);
    actions.p->drawLine(xo, yo, xk, yk);
}

int edge_by_name(Edge edge, int i) {
    switch (i) {
        case FROM:
            return edge.from_point;
        case TO:
            return edge.to_point;
        default:
            return 0;
    }
}

int read_edge(Edge &edge, File &file) {
    if (readf(edge.from_point, file) > 0) {
        return INCORRECT;
    }
    if (readf(edge.to_point, file) > 0) {
        return INCORRECT;
    }
    return OK;
}

void write_edge(File &file, Edge edge) {
    writef(file, edge.from_point);
    writef(file, ' ');
    writef(file, edge.to_point);
    writef(file, '\n');
}
