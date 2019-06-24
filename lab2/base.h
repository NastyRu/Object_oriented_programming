#ifndef BASE_H
#define BASE_H

class My_Base {
public:
  virtual ~My_Base() = default;
  virtual int len() const = 0;
  virtual void pop_back() = 0;
  virtual void pop_front() = 0;
protected:
  virtual void del(int i) = 0;
  int n;
};

#endif
