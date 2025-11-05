#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>
#include "queue.h"


template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {

  int real = (mFront + pos) % mCap;
  int val = mData[real];

  for(int i=real; i!=(mFront+mSize-1)%mCap ; i++,i%=mCap) {
    int now = i, nxt = (i+1)%mCap;
    mData[now] = mData[nxt];
  }

  mData[(mFront+mSize-1)%mCap] = val;
}

#endif
