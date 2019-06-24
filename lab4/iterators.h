#ifndef ITERATORS_H
#define ITERATORS_H

#include <stdlib.h>
#include <iterator>
#include <vector>

using namespace std;

class Object;
class Position;

typedef vector<shared_ptr<Object>>::iterator objects_iterator;
typedef vector<shared_ptr<Position>>::iterator positions_iterator;

#endif // ITERATORS_H
