#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"
using std::cout;

template <typename T> void CP::queue<T>::merge_greater(CP::queue<T> &other) {
  queue<T> x, y;

  if(mSize == other.mSize) return ;

  while (other.size()) {
    int a = front();
    pop();
    int b = other.front();
    other.pop();
    x.push(a);
    if (a < b) {
      x.push(b);
    } else
      y.push(b);
  }
  other = y;

  int n = x.size();
  ensureCapacity(n + mSize);
  for (int i = 0; i < n; ++i) {
    int to = (mFront - n + i + mCap) % mCap;
    mData[to] = x.front();
    x.pop();
  }

  mFront = (mFront - n + mCap) % mCap;
  mSize += n;
}

#endif
