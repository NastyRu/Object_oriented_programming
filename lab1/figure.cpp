#include "figure.h"
#include <QDebug>

int drawfigure(Figure my_figure, Actions actions) {
    int err = draw_edges(my_figure.edges, my_figure.points, actions);
    return err;
}

void centre(Figure &my_figure) {
    Point_3d t;
    t.x = mean_value(my_figure.points, X_NAME);
    t.y = mean_value(my_figure.points, Y_NAME);
    t.z = mean_value(my_figure.points, Z_NAME);
    my_figure.centre = t;
}

Figure init() {
    Figure my_figure;
    return my_figure;
}

int read_figure(Figure &my_figure, File &file) {
    int err1 = read_points(my_figure.points, file);
    if (OK != err1) {
        return err1;
    }
    int err2 = read_edges(my_figure.edges, file);
    if (OK != err2) {
        free_mas(my_figure.points);
        return err2;
    }

    return OK;
}

int write_figure(File &file, Figure &my_figure) {
    int err1 = write_points(file, my_figure.points);
    if (OK != err1) {
        return err1;
    }
    int err2 = write_edges(file, my_figure.edges);
    if (OK != err2) {
        return err2;
    }

    return OK;
}

int readfromfile(Figure &my_figure, Actions actions) {
    File file;
    int err = 0;
    err = open_file(file, actions.filename);
    if (OK != err)
        return err;

    Figure temp_figure;
    if ((err = read_figure(temp_figure, file)) == OK ) {
        free(my_figure);
        my_figure = temp_figure;
    }

    close_file(file);

    return err;
}

int writetofile(Figure my_figure, Actions actions) {
    File file;
    int err = 0;
    err = open_file(file, actions.filename);
    if (OK != err)
        return err;

    if (OK != write_figure(file, my_figure)) {
        err = INCORRECT;
    }

    close_file(file);
    return err;
}

void free(Figure &my_figure) {
    free_mas(my_figure.points);
    free_mas(my_figure.edges);
}
