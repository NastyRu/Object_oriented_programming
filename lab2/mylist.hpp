#include "mylist.h"
#include "node.hpp"

template <typename T>
My_list<T>::My_list() {
  first = nullptr;
  last = nullptr;
  n = 0;
}

template <typename T>
My_list<T>::My_list(const My_list<T>& list) {
  copy(*this, list);
}

template <typename T>
My_list<T>::My_list(size_t size, T* array) {
  n = 0;
  first = nullptr;
  last = nullptr;
  for (int i = 0; i < size; i++) {
    this->push_back(array[i]);
  }
}

template <typename T>
My_list<T>::My_list(int kol, ...) {
  n = 0;
  first = nullptr;
  last = nullptr;
  if (n < 0) {
      throw Kol_error();
  }
  va_list va;
  va_start(va, kol);
  for (int i = 0; i < kol; i++) {
      T elem = va_arg(va, T);
      this->push_back(elem);
  }
  va_end(va);
}

template <typename T>
My_list<T>::My_list(std::initializer_list<T> list) {
  n = 0;
  for (T elem : list) {
    this->push_back(elem);
  }
}

template <typename T>
My_list<T>& My_list<T>::operator= (const My_list& list) {
  copy(*this, list);
  return *this;
}

template <typename T>
void My_list<T>::copy(My_list<T>& l1, const My_list<T>& l2) {
  l1.del_list();
  l1.n = 0;
  for (shared_ptr< Node <T> > iter = l2.first; iter != nullptr; iter = iter->get_next()) {
    l1.push_back(iter->get_elem());
  }
}

template <typename T>
My_list<T>::My_list(My_list<T>&& list) {
  transfer(*this, list);
}

template <typename T>
My_list<T>& My_list<T>::operator= (My_list<T>&& list) {
  transfer(*this, list);
  return *this;
}

template <typename T>
void My_list<T>::transfer(My_list<T>& l1, My_list<T>& l2) {
  l1.n = l2.n;
  l1.first = l2.first;
  l1.last = l2.last;

  l2.first = nullptr;
  l2.last = nullptr;
}

template <typename T>
My_list<T>::~My_list() {
  this->del_list();
}

template <typename T>
void My_list<T>::del_list() {
  first = last = nullptr;
  n = 0;
}

template <typename T>
void My_list<T>::push_back(const T& elem) {
  insert(n, elem);
}

template <typename T>
void My_list<T>::push_front(const T& elem) {
  n++;
  shared_ptr< Node <T> > node = make_shared< Node<T> >();
  if (node == nullptr) {
    throw Mem_error();
  }
  node->set_elem(elem);
  node->set_next(first);
  first = node;
}

template <typename T>
void My_list<T>::insert_after(const My_Iterator<T> &elem, const T& newelem) {
  shared_ptr< Node <T> > node = make_shared< Node<T> >();
  if (node == nullptr) {
    throw Mem_error();
  }
  node->set_elem(newelem);
  shared_ptr< Node <T> > ptr = elem.node.lock()->get_next();
  elem.node.lock()->set_next(node);
  node->set_prev(elem.node.lock());
  node->set_next(ptr);
}

template <typename T>
void My_list<T>::insert_after(const Const_Iterator<T> &elem, const T& newelem) {
  shared_ptr< Node <T> > node = make_shared< Node<T> >();
  if (node == nullptr) {
    throw Mem_error();
  }
  node->set_elem(newelem);
  shared_ptr< Node <T> > ptr = elem.node.lock()->get_next();
  elem.node.lock()->set_next(node);
  node->set_prev(elem.node.lock());
  node->set_next(ptr);
}

template <typename T>
void My_list<T>::insert_before(const My_Iterator<T> &elem, const T& newelem) {
  shared_ptr< Node <T> > node = make_shared< Node<T> >();
  if (node == nullptr) {
    throw Mem_error();
  }
  node->set_elem(newelem);
  shared_ptr< Node <T> > ptr = elem.node.lock()->get_prev();
  node->set_next(elem.node.lock());
  node->set_prev(ptr);
  ptr->set_next(node);
  elem.node.lock()->set_prev(node);
}

template <typename T>
void My_list<T>::insert_before(const Const_Iterator<T> &elem, const T& newelem) {
  shared_ptr< Node <T> > node = make_shared< Node<T> >();
  if (node == nullptr) {
    throw Mem_error();
  }
  node->set_elem(newelem);
  shared_ptr< Node <T> > ptr = elem.node.lock()->get_prev();
  node->set_next(elem.node.lock());
  node->set_prev(ptr);
  ptr->set_next(node);
}

template <typename T>
My_list<T> My_list<T>::operator+ (const T& elem) {
  My_list newlist = My_list(*this);
  newlist.insert(n, elem);
  return My_list<T>(newlist);
}

template <typename T>
My_list<T>& My_list<T>::operator+= (const T& elem) {
  insert(n, elem);
  return *this;
}

template <typename T>
My_list<T> My_list<T>::operator+ (const My_list<T>& list) {
  My_list newlist = *this;
  merge(newlist, list);
  return My_list<T>(newlist);
}

template <typename T>
My_list<T>& My_list<T>::operator+= (const My_list<T>& list) {
  merge(*this, list);
  return *this;
}

template <typename T>
void My_list<T>::merge(My_list<T>& l1, const My_list<T>& l2) {
  for (shared_ptr< Node <T> > iter = l2.first; iter != nullptr; iter = iter->get_next()) {
    l1.push_back(iter->get_elem());
  }
}

template <typename T>
void My_list<T>::insert(int i, const T& elem) {
  if (i > n || i < 0) {
    throw Kol_error();
  }

  n++;
  shared_ptr< Node <T> > node = make_shared< Node<T> >();
  if (node == nullptr) {
    throw Mem_error();
  }
  node->set_elem(elem);

  if (0 == i) {
    node->set_next(first);
    first = node;
    last = node;
    return;
  }

  shared_ptr< Node <T> > iter = first;
  for (int j = 0; j < i - 1 && iter != nullptr; iter = iter->get_next(), j++);

  shared_ptr< Node <T> > tmp = iter->get_next();
  iter->set_next(node);
  node->set_prev(iter);
  node->set_next(tmp);

  if (i == n - 1) {
    last = node;
  }
}

template <typename T>
My_list<T>& My_list<T>::operator-- () {
  del(n - 1);
  return *this;
}

template <typename T>
My_list<T>& My_list<T>::operator-= (const T &x) {
  int i = index(x);
  del(i);

  return *this;
}

template <typename T>
void My_list<T>::remove(const My_Iterator<T> &elem) {
  shared_ptr< Node <T> > tmp = elem.node.lock()->get_prev();
  if (nullptr == tmp) {
    first = elem.node.lock()->get_next();
    return;
  }
  tmp->set_next(elem.node.lock()->get_next());
}

template <typename T>
void My_list<T>::remove(const Const_Iterator<T> &elem) {
  shared_ptr< Node <T> > tmp = elem.node.lock()->get_prev();
  if (nullptr == tmp) {
    first = elem.node.lock()->get_next();
    return;
  }
  tmp->set_next(elem.node.lock()->get_next());
}

template <typename T>
void My_list<T>::pop_back() {
  del(n - 1);
}

template <typename T>
void My_list<T>::pop_front() {
  del(0);
}

template <typename T>
void My_list<T>::del(int i) {
  if (0 == n) {
    throw Empty_error();
  }
  if (i < 0 || i >= n) {
    throw Kol_error();
  }
  n--;

  if (0 == i) {
    first = first->get_next();
    first->set_prev(nullptr);
    return;
  }
  if (n == i) {
    last = last->get_prev();
    last->set_next(nullptr);
    return;
  }

  shared_ptr< Node <T> > iter = first;
  for (int j = 0; j < i && iter != nullptr; iter = iter->get_next(), j++);

  shared_ptr< Node <T> > before = iter->get_prev();
  shared_ptr< Node <T> > after = iter->get_next();
  before->set_next(after);
  after->set_prev(before);
}

template <typename T>
int My_list<T>::index(T x) {
  int k = 0;
  /*shared_ptr< Node <T> > node = first;
  while (node != nullptr && x != node->get_elem()) {
    k++;
    node = node->get_next();
  }*/
  /*My_Iterator lBegin = list.begin();
  My_Iterator lEnd = list.end();
  for (; lBegin != lEnd; ++lBegin)
  {
      (*lBegin) = 10;
  }*/
  My_Iterator lb = begin();
  My_Iterator le = end();
  for (; lb != le; lb++)
  {
    if (*lb == x) {
      break;
    }
    k++;
  }
  if (n == k) {
    k = -1;
  }
  return k;
}

template <typename T>
int My_list<T>::count(T x) {
  int k = 0;
  shared_ptr< Node <T> > node = first;
  while (node != nullptr) {
    if (x == node->get_elem()) {
      k++;
    }
    node = node->get_next();
  }

  return k;
}

template <typename T>
int My_list<T>::len() const {
  return n;
}

template <typename T>
bool My_list<T>::equal(My_list<T>& list) {
  if (this->len() != list.len()) {
    return false;
  }

  shared_ptr< Node <T> > n1 = first;
  shared_ptr< Node <T> > n2 = list.first;
  while (n1 != nullptr) {
    if (n1->get_elem() != n2->get_elem()) {
      return false;
    }
    n1 = n1->get_next();
    n2 = n2->get_next();
  }
  return true;
}

template <typename T>
bool My_list<T>::operator!= (My_list<T>& list) {
  return !equal(list);
}

template <typename T>
bool My_list<T>::operator== (My_list<T>& list) {
  return equal(list);
}

template <typename T>
shared_ptr< Node <T> > My_list<T>::get_first() const {
  return first;
}

template <typename T>
void My_list<T>::print() {
  cout << this->n << endl;
  shared_ptr< Node <T> > node = first;
  while (node != nullptr) {
    node->print_node();
    node = node->get_next();
  }
  cout << endl;
}

template <typename T>
My_Iterator<T> My_list<T>::begin() {
  return My_Iterator<T>(first);
}

template <typename T>
My_Iterator<T> My_list<T>::end() {
  return My_Iterator<T>(nullptr);
}

template <typename T>
Const_Iterator<const T> My_list<T>::begin() const {
  return Const_Iterator<const T>(first);
}

template <typename T>
Const_Iterator<const T> My_list<T>::end() const {
  return Const_Iterator<const T>(nullptr);
}
