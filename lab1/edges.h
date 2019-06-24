#ifndef EDGES_H
#define EDGES_H

#include "edge.h"

#pragma pack(push, 1)
struct Edges {
    int n = 0;
    Edge *edges_array = nullptr;
};
#pragma pack(pop)

int draw_edges(Edges , Points , Actions );
int write_edges(File &, Edges );
int read_edges(Edges &, File &);
void free_mas(Edges &);
void allocate(Edges &);

#endif // EDGES_H
