#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>
#include "queue.h"

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
  int val = mData[(mFront + pos) % mCap];

  for(int i=pos-1; i>=0; --i) {
    int now = (mFront + i) % mCap;
    int nxt = (mFront + i + 1) % mCap;
    mData[nxt] = mData[now];
  }

  mData[mFront] = val;
}

#endif
