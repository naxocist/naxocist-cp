#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"
using std::cout;

template <typename T>
void CP::queue<T>::insert_shuffle(std::vector<T> items, size_t pos) {
  ensureCapacity(mSize + items.size());

  queue<T> t;
  int i = 0, j = 0;
  while(size()) {
    T f = front(); pop();
    if(i >= pos) {
      if(j < (int)items.size()) t.push(items[j ++]);
    }
    t.push(f);
    i ++;
  }

  while(j < (int)items.size()) {
    t.push(items[j ++]);
  }

  *this = t;
  mSize = t.mSize;
}

#endif
