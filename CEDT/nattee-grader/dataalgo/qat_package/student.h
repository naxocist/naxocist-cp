#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "queue.h"

template <typename T>
T CP::queue<T>::operator[](int idx) {
  int t = mFront + idx;
  if(idx < 0) t += mSize;
  t %= mCap, t += mCap, t %= mCap;
  return mData[t];
}

#endif
