#ifndef OBJECTS_H
#define OBJECTS_H

#include <vector>
#include "iterators.h"

using namespace std;

class Object
{
public:
    Object() {}
    ~Object() {}

    virtual bool is_visible() = 0;
    virtual bool is_compose() = 0;
};

class Compose_object : public Object
{
public:
    Compose_object() {}
    ~Compose_object() {}

    bool is_compose() override {return true;}

    void add_object(shared_ptr<Object> obj);
    void delete_object(objects_iterator obj);
private:
    vector<shared_ptr<Object>> objects;
};

class Visible_object : public Object
{
public:
    Visible_object() {}
    ~Visible_object() {}

    bool is_visible() override {return true;}
    bool is_compose() override {return false;}
};

class Unvisible_object : public Object
{
public:
    Unvisible_object() {}
    ~Unvisible_object() {}

    bool is_visible() override {return false;}
    bool is_compose() override {return false;}
};

#endif // OBJECTS_H
