#include "entry.h"
#include "operation.h"

int entry_func(const Act a, Actions actions) {
    static Figure my_figure = init();
    int error = 0;
    switch(a) {
    case sc:
        error = scale(my_figure, actions);
        break;
    case rot:
        error = rotate(my_figure, actions);
        break;
    case off:
        error = offset(my_figure, actions);
        break;
    case load:
        error = readfromfile(my_figure, actions);
        break;
    case save:
        error = writetofile(my_figure, actions);
        break;
    case draw:
        error = drawfigure(my_figure, actions);
        break;
    case ex:
        free(my_figure);
        break;
     default:
        error = INCORRECT;
    }
    return error;
}
