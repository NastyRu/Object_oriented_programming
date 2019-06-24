#include "objects.h"

void Compose_object::add_object(shared_ptr<Object> obj) {
    objects.push_back(obj);
}

void Compose_object::delete_object(objects_iterator obj) {
    objects.erase(obj);
}
