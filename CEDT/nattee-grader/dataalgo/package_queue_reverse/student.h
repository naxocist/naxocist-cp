#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cassert>
#include "queue.h"

template <typename T>
void CP::queue<T>::reverse(int a,int b) {

  int len = b - a + 1;
  for(int i=0; i<len/2; ++i) {
    int x = (mFront + i + a) % mCap, y = (mFront + b - i + mCap) % mCap;
    std::swap(mData[x], mData[y]);
  }
}

#endif
