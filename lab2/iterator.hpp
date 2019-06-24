#include "iterator.h"

template <typename T>
const T& My_Iterator<T>::operator*() const {
  if (node.expired() || nullptr == node.lock()) {
    throw Iterator_error();
  }
  return node.lock()->elem;
}

template <typename T>
const T* My_Iterator<T>::operator->() const {
  if (node.expired() || nullptr == node.lock()) {
    throw Iterator_error();
  }
  return &node.lock()->elem;
}

template <typename T>
T& My_Iterator<T>::operator*() {
  if (node.expired() || nullptr == node.lock()) {
    throw Iterator_error();
  }
  return node.lock()->elem;
}

template <typename T>
T* My_Iterator<T>::operator->() {
  if (node.expired() || nullptr == node.lock()) {
    throw Iterator_error();
  }
  return &node.lock()->elem;
}

template <typename T>
My_Iterator<T>& My_Iterator<T>::operator++() {
  if (node.expired() || nullptr == node.lock()) {
    throw Iterator_error();
  }
  node = node.lock()->next;
  return *this;
}

template <typename T>
My_Iterator<T> My_Iterator<T>::operator++(int) {
  if (node.expired() || nullptr == node.lock()) {
    throw Iterator_error();
  }
  node = node.lock()->next;
  return *this;
}

template <typename T>
My_Iterator<T>& My_Iterator<T>::operator--() {
  if (node.expired() || nullptr == node.lock()) {
    throw Iterator_error();
  }
  node = node.lock()->prev;
  return *this;
}

template <typename T>
My_Iterator<T> My_Iterator<T>::operator--(int) {
  if (node.expired() || nullptr == node.lock()) {
    throw Iterator_error();
  }
  node = node.lock()->prev;
  return *this;
}

template <typename T>
bool My_Iterator<T>::operator==(My_Iterator const& iter) {
  return (node.lock() == iter.node.lock());
}

template <typename T>
bool My_Iterator<T>::operator!=(My_Iterator const& iter) {
  return (node.lock() != iter.node.lock());
}

template <typename T>
My_Iterator<T>::operator bool() const {
  return !(node.expired() || nullptr == node.lock());
}

template <typename T>
const T& Const_Iterator<T>::operator*() const {
  if (node.expired() || nullptr == node.lock()) {
    throw Iterator_error();
  }
  return node.lock()->elem;
}

template <typename T>
const T* Const_Iterator<T>::operator->() const {
  if (node.expired() || nullptr == node.lock()) {
    throw Iterator_error();
  }
  return &node.lock()->elem;
}

template <typename T>
Const_Iterator<T>& Const_Iterator<T>::operator++() {
  if (node.expired() || nullptr == node.lock()) {
    throw Iterator_error();
  }
  node = node.lock()->next;
  return *this;
}

template <typename T>
Const_Iterator<T> Const_Iterator<T>::operator++(int) {
  if (node.expired() || nullptr == node.lock()) {
    throw Iterator_error();
  }
  node = node.lock()->next;
  return *this;
}

template <typename T>
Const_Iterator<T>& Const_Iterator<T>::operator--() {
  if (node.expired() || nullptr == node.lock()) {
    throw Iterator_error();
  }
  node = node.lock()->prev;
  return *this;
}

template <typename T>
Const_Iterator<T> Const_Iterator<T>::operator--(int) {
  if (node.expired() || nullptr == node.lock()) {
    throw Iterator_error();
  }
  node = node.lock()->prev;
  return *this;
}

template <typename T>
bool Const_Iterator<T>::operator==(Const_Iterator const& iter) {
  return (node.lock() == iter.node.lock());
}

template <typename T>
bool Const_Iterator<T>::operator!=(Const_Iterator const& iter) {
  return (node.lock() != iter.node.lock());
}

template <typename T>
Const_Iterator<T>::operator bool() const {
  return !(node.expired() || nullptr == node.lock());
}
