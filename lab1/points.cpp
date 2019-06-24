#include "points.h"
#include "memory.h"
#include <QDebug>

int offset_points(Points &points, Actions actions) {
    for (int i = 0; i < points.n; i++) {
        offset_point(points.points_array[i], actions);
    }
    return OK;
}

int scale_points(Points &points, Point_3d centre, Actions actions) {
    for (int i = 0; i < points.n; i++) {
        scale_point(points.points_array[i], centre, actions);
    }
    return OK;
}

int rotate_points(Points &points, Point_3d centre, Actions actions) {
    for (int i = 0; i < points.n; i++) {
        rotate_point(points.points_array[i], centre, actions);
    }
    return OK;
}

int mean_value(Points points, int type_point) {
    int s = 0;
    for (int i = 0; i < points.n; i++) {
        s += point_by_name(points.points_array[i], type_point);
    }

    return int(s / points.n);
}

int read_points(Points &points, File &file) {
    if (readf(points.n, file) > 0 || points.n <= 0) {
        return INCORRECT;
    }
    allocate(points);

    int err = 0;
    for (int i = 0; i < points.n && 0 == err; i++) {
        err = read_point(points.points_array[i], file);
    }

    if (err != 0) {
        free_mas(points);
    }
    return err;
}

int write_points(File &file, Points points) {
    if (points.n <= 0) {
        return INCORRECT;
    }
    file.file << points.n << endl;
    for (int i = 0; i < points.n; i++) {
        write_point(file, points.points_array[i]);
    }
    return OK;
}

void free_mas(Points &points) {
    if (nullptr != points.points_array) {
        delete [] points.points_array;
        points.n = 0;
    }
}

void allocate(Points &points) {
    points.points_array = new Point_3d[points.n];
}
