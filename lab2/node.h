#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template <typename T>
class My_Iterator;

template <typename T>
class Node {
  friend My_Iterator<T>;
public:
  Node();
  ~Node();
  Node(const Node<T>& node);
  Node<T>& operator= (const Node& node);

  shared_ptr < Node<T> > get_next();
  shared_ptr < Node<T> > get_prev();
  void set_next(shared_ptr < Node<T> > next);
  void set_prev(shared_ptr < Node<T> > prev);
  void set_elem(const T& elem);
  T get_elem();
  void print_node();
  void swap();
  void swap(Node<T>& n1, Node<T>& n2);
private:
  T elem;
  shared_ptr < Node<T> > prev;
  shared_ptr < Node<T> > next;

  void copy(Node<T>& n1, const Node<T>& n2);
};

#endif
