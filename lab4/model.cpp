#include "model.h"

Model::Model(vector<Point_3d> points, vector<Edge> edges) {
    this->points = points;
    this->edges = edges;
}

void Model::add_point(Point_3d point) {
    points.push_back(point);
}

void Model::add_edge(Edge edge) {
    edges.push_back(edge);
}

vector<Point_3d> Model::get_points() {
    return points;
}

vector<Point_3d> &Model::get_var_points() {
    return points;
}

vector<Edge> Model::get_edges() {
    return edges;
}

int Model::get_kol_points() {
    return int(points.size());
}

int Model::get_kol_edges() {
    return int(edges.size());
}
