#ifndef POINTS_H
#define POINTS_H

#include "point.h"

#pragma pack(push, 1)
struct Points {
    int n = 0;
    Point_3d *points_array = nullptr;
};
#pragma pack(pop)

int offset_points(Points &, Actions );
int scale_points(Points &, Point_3d , Actions );
int rotate_points(Points &, Point_3d , Actions );
int mean_value(Points , int );
int write_points(File &, Points );
int read_points(Points &, File &);
void free_mas(Points &);
void allocate(Points &);

#endif // POINTS_H
