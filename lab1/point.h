#ifndef POINT_H
#define POINT_H

#include "workwithfile.h"
#include <math.h>

#define TO_3D (0.5)
#define RAD 0.017453
#define OK 0
#define INCORRECT -2

struct Point_3d {
    int x;
    int y;
    int z;
};

enum points_names {
    X_NAME, Y_NAME, Z_NAME
};

struct Point_2d {
    int x;
    int y;
};

int from_3d_to_2d(int , int );
int point_by_name(Point_3d , int );
void scale_point(Point_3d &, Point_3d , Actions );
void offset_point(Point_3d &, Actions );
void rotate_point(Point_3d &, Point_3d , Actions );
int read_point(Point_3d &, File &);
void write_point(File &, Point_3d );

#endif // POINT_H
