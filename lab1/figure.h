#ifndef FIGURE_H
#define FIGURE_H

#include "edges.h"

struct Figure{
    Edges edges;
    Points points;
    Point_3d centre;
};

int drawfigure(Figure, Actions);
void centre(Figure &);
Figure init();
int read_figure(Figure &, File &);
int write_figure(File &, Figure &);
int readfromfile(Figure & , Actions );
int writetofile(Figure, Actions );
void free(Figure &);

#endif // FIGURE_H
