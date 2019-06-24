#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include "points.h"

using namespace std;

class Matrix
{
public:
    Matrix() {}
    ~Matrix() {}

    Point_3d operator *(const Point_3d &point);

private:
    vector<vector<double>> matrix;
    int n = 0;
};

#endif // MATRIX_H
