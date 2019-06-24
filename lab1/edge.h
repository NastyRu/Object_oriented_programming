#ifndef EDGE_H
#define EDGE_H

#include "points.h"

enum edge_name {
    FROM, TO
};

struct Edge {
    int from_point;
    int to_point;
};

int edge_by_name(Edge , int);
void draw_edge(Point_3d , Point_3d , Actions );
void write_edge(File &, Edge );
int read_edge(Edge &, File &);

#endif // EDGE_H
