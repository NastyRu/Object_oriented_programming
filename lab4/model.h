#ifndef MODEL_H
#define MODEL_H

#include "objects.h"
#include "points.h"
#include "edges.h"
#include "base_draw.h"

using namespace std;

class Model : public Visible_object
{
public:
    Model() {}
    ~Model() {}

    Model(vector<Point_3d> points, vector<Edge> edges);

    void add_point(Point_3d point);
    void add_edge(Edge edge);

    vector<Point_3d> get_points();
    vector<Edge> get_edges();

    int get_kol_points();
    int get_kol_edges();

    vector<Point_3d> &get_var_points();
private:
    vector<Point_3d> points;
    vector<Edge> edges;
};

#endif // MODEL_H
