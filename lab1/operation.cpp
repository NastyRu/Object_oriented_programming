#include "operation.h"

int offset(Figure &my_figure, Actions actions) {
    if (0 == my_figure.points.n) {
        return NO_FIGURE;
    }

    offset_points(my_figure.points, actions);
    return OK;
}

int scale(Figure &my_figure, Actions actions) {
    if (0 == my_figure.points.n) {
        return NO_FIGURE;
    }

    centre(my_figure);
    scale_points(my_figure.points, my_figure.centre, actions);

    return OK;
}

int rotate(Figure &my_figure, Actions actions) {
    if (0 == my_figure.points.n) {
        return NO_FIGURE;
    }

    centre(my_figure);
    rotate_points(my_figure.points, my_figure.centre, actions);

    return OK;
}
