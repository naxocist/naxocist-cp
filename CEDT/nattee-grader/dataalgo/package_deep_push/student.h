#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "stack.h"

template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
  ensureCapacity(mSize + 1);

  int p = mSize - pos;
  for(int i=mSize; i>p; i--) {
    mData[i] = mData[i-1];
  }
  mData[p] = value;
  mSize ++;
}

#endif
