#ifndef MODEL_BUILDER_H
#define MODEL_BUILDER_H

#include "base_builder.h"
#include "model.h"
#include "exceptions.h"

using namespace std;

class Model_builder : public Base_builder
{
public:
    Model_builder() {}
    ~Model_builder() {}

    void build_model();
    void build_edge(int begin, int end);
    void build_point(double x, double y, double z);

    shared_ptr<Model> get_result();

private:
    shared_ptr<Model> model;
};

#endif // MODEL_BUILDER_H
