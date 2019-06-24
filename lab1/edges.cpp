#include "edges.h"
#include "memory.h"

int draw_edges(Edges edges, Points points, Actions actions) {
    Point_3d k;
    Point_3d o;
    if (edges.n <= 0) {
        return INCORRECT;
    }
    for (int i = 0; i < edges.n; i++) {
        o = points.points_array[edge_by_name(edges.edges_array[i], FROM)];
        k = points.points_array[edge_by_name(edges.edges_array[i], TO)];
        draw_edge(o, k, actions);
    }
    return OK;
}

int read_edges(Edges &edges, File &file) {
    if (readf(edges.n, file) > 0 || edges.n <= 0) {
        return INCORRECT;
    }
    allocate(edges);

    int err = 0;
    for (int i = 0; i < edges.n && 0 == err; i++) {
        err = read_edge(edges.edges_array[i], file);
    }

    if (err != 0) {
        free_mas(edges);
    }
    return err;
}

int write_edges(File &file, Edges edges) {
    if (edges.n <= 0) {
        return INCORRECT;
    }
    file.file << edges.n << endl;
    for (int i = 0; i < edges.n; i++) {
        write_edge(file, edges.edges_array[i]);
    }
    return OK;
}

void free_mas(Edges &edges) {
    if (nullptr != edges.edges_array) {
        delete [] edges.edges_array;
        edges.n = 0;
    }
}

void allocate(Edges &edges) {
    edges.edges_array = new Edge[edges.n];
}
