#include "node.h"

template <typename T>
Node<T>::Node() {
  prev = nullptr;
  next = nullptr;
  elem = 0;
}

template <typename T>
Node<T>::~Node() {
  prev = nullptr;
  next = nullptr;
  elem = 0;
}

template <typename T>
Node<T>::Node(const Node<T>& node) {
  copy(*this, node);
}

template <typename T>
Node<T>& Node<T>::operator= (const Node& node) {
  copy(*this, node);
}

template <typename T>
void Node<T>::copy(Node<T>& n1, const Node<T>& n2) {
  n1.prev = n2.prev;
  n1.next = n2.next;
  n1.elem = n2.elem;
}

template <typename T>
shared_ptr < Node<T> > Node<T>::get_next() {
  return next;
}

template <typename T>
shared_ptr < Node<T> > Node<T>::get_prev() {
  return prev;
}

template <typename T>
void Node<T>::set_next(shared_ptr < Node<T> > next) {
  this->next = next;
}

template <typename T>
void Node<T>::set_prev(shared_ptr < Node<T> > prev) {
  this->prev = prev;
}

template <typename T>
void Node<T>::set_elem(const T& elem) {
  this->elem = elem;
}

template <typename T>
T Node<T>::get_elem() {
  return this->elem;
}

template <typename T>
void Node<T>::print_node() {
  cout << elem << " ";
}

template <typename T>
void Node<T>::swap() {
  shared_ptr< Node <T> > tmp = prev;
  prev = next;
  next = tmp;
}

template <typename T>
void Node<T>::swap(Node<T>& n1, Node<T>& n2) {
  shared_ptr< Node <T> > tmp = n1;
  n1 = n2;
  n2 = tmp;
}
