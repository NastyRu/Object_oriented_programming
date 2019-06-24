#include "matrix.h"

Point_3d Matrix::operator *(const Point_3d &point) {
    double tmp[3] = {0};
    for (int i = 0; i < 3; i++) {
        tmp[i] = point.get_x() * matrix[i][0] + point.get_y() * matrix[i][1] * point.get_z() * matrix[i][2];
    }

    Point_3d result = Point_3d(tmp[0], tmp[1], tmp[2]);

    return result;
}
