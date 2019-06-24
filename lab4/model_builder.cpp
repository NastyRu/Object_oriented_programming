#include "model_builder.h"
#include <QDebug>

void Model_builder::build_model() {
    model = make_shared<Model>();
    if (!model) {
        throw Builder_exceptions();
    }
}

void Model_builder::build_point(double x, double y, double z) {
    if (!model) {
        throw Builder_exceptions();
    } else {
        model->add_point(Point_3d(x, y, z));
    }
}

void Model_builder::build_edge(int begin, int end) {
    if (!model) {
        throw Builder_exceptions();
    } else {
        model->add_edge(Edge(begin, end));
    }
}

shared_ptr<Model> Model_builder::get_result() {
    return model;
}
