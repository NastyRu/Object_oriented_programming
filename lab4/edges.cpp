#include "edges.h"

Edge::Edge(const int begin, int end) {
    this->begin = begin;
    this->end = end;
}

void Edge::set_begin(const int begin) {
    this->begin = begin;
}

void Edge::set_end(int end) {
    this->end = end;
}

int Edge::get_begin() const {
    return begin;
}

int Edge::get_end() const {
    return end;
}
