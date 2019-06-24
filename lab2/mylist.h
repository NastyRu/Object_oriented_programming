#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <cstdarg>
#include "iterator.h"
#include "error.h"
#include "base.h"

using namespace std;

template <typename T>
class My_list : public My_Base {
public:
  My_list();
  ~My_list() override;
  explicit My_list(const My_list<T>& list);
  My_list(My_list<T>&& list);
  My_list(size_t size, T* array);
  My_list(int kol, ...);
  My_list(std::initializer_list<T> list);

  My_list<T>& operator= (const My_list<T>& list);
  My_list<T>& operator= (My_list<T>&& list);

  void push_back(const T& elem);
  void push_front(const T& elem);
  My_list<T> operator+ (const T& elem);
  My_list<T> operator+ (const My_list<T>& list);
  My_list<T>& operator+= (const T& elem);
  My_list<T>& operator+= (const My_list<T>& list);
  void insert_after(const My_Iterator<T> &elem, const T& newelem);
  void insert_after(const Const_Iterator<T> &elem, const T& newelem);
  void insert_before(const My_Iterator<T> &elem, const T& newelem);
  void insert_before(const Const_Iterator<T> &elem, const T& newelem);

  My_list<T>& operator-- ();
  My_list<T>& operator-= (const T& x);
  void remove(const My_Iterator<T> &elem);
  void remove(const Const_Iterator<T> &elem);
  void pop_back() override;
  void pop_front() override;

  int index(T x);
  int count(T x);

  bool operator== (My_list<T>& list);
  bool operator!= (My_list<T>& list);
  bool equal(My_list<T>& list);

  My_Iterator<T> begin();
  My_Iterator<T> end();
  Const_Iterator<const T> begin() const;
  Const_Iterator<const T> end() const;

  int len() const override;
  friend ostream& operator << (ostream &stream, const My_list<T> &list) {
      stream << list.len() << endl;
      shared_ptr< Node <T> > node = list.get_first();
      while (node != nullptr) {
        stream << node->get_elem() << " ";
        node = node->get_next();
      }
      stream << endl;
      return stream;
  }
  void print();

private:
  shared_ptr< Node<T> > first;
  shared_ptr< Node<T> > last;

  void copy(My_list<T>& l1, const My_list<T>& l2);
  void transfer(My_list<T>& l1, My_list<T>& l2);
  void merge(My_list<T>& l1, const My_list<T>& l2);
  void insert(int i, const T& elem);
  void del(int i) override;
  void del_list();
protected:
  shared_ptr< Node <T> > get_first() const;
};

#endif
