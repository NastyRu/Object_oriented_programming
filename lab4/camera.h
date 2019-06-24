#ifndef CAMERA_H
#define CAMERA_H

#include "objects.h"
#include "matrix.h"
#include "points.h"

class Camera : public Unvisible_object
{
public:
    Camera() {}
    ~Camera() {}
    void set_position(const Point_3d &point);
    void set_target(const Point_3d &point);

    void pitch(const double x);
    void yaw(const double y);
    void roll(const double z);

private:
    Matrix matrix;
};

#endif // CAMERA_H
