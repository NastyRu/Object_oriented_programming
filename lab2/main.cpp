#include "mylist.hpp"
#include "iterator.hpp"

int main() {
  My_list<int> newlist {0,-1,-2,3};
  newlist.push_front(1);
  newlist.push_back(5);
  newlist.pop_front();
  newlist.pop_back();
  cout << newlist;

  My_list<int> list {0,1,-2,3};

  cout << list;

  My_list<int> list1 {0,1,-2,3};

  //cout << list1.index(1) << endl;
  //list1.insert(-1,5);

  My_Iterator lBegin = list.begin();
  My_Iterator<int> end;
  for (int el : list1) {
    cout << el << ' ';
  }
  list.insert_after(lBegin, 5);
  list.remove(lBegin);
  //list.remove(lBegin);
  cout << endl;
  cout << list;
  cout << bool(lBegin) << " " << bool(end) << endl;
  try {
    My_Iterator<int> lb = list.begin();
    while (true) lb++;
  } catch (Iterator_error& e){
    cout << e.what() << endl;
  }
}
