#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <iterator>
 
template <typename T>
class My_list;

using namespace std;
template <typename T>

class My_Iterator : public std::iterator<std::input_iterator_tag, T> {
  friend My_list<T>;
public:
  My_Iterator() {};
  My_Iterator(shared_ptr < Node<T> > node) : node(node) {};

  const T& operator*() const;
  const T* operator->() const;
  T& operator*();
  T* operator->();
  My_Iterator<T>& operator++();
  My_Iterator<T> operator++(int);
  My_Iterator<T>& operator--();
  My_Iterator<T> operator--(int);
  bool operator==(My_Iterator const& iter);
  bool operator!=(My_Iterator const& iter);

  operator bool() const;

private:
  weak_ptr < Node<T> > node;
};

template <typename T>
class Const_Iterator : public std::iterator<std::input_iterator_tag, T> {
  friend My_list<T>;
public:
  Const_Iterator() {};
  Const_Iterator(shared_ptr < Node<T> > node) : node(node) {};

  const T& operator*() const;
  const T* operator->() const;
  Const_Iterator& operator++();
  Const_Iterator operator++(int);
  Const_Iterator& operator--();
  Const_Iterator operator--(int);
  bool operator==(Const_Iterator const& iter);
  bool operator!=(Const_Iterator const& iter);

  operator bool() const;

private:
  weak_ptr < Node<T> > node;
};

#endif
