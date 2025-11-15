#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T> void CP::stack<T>::jenga(char c, int a) {
  if (c == 'p') {
    int idx = mSize - 1 - a;
    T t = mData[idx];
    for (int i = idx; i + 1 < mSize; ++i) {
      mData[i] = mData[i + 1];
    }
    mData[mSize - 1] = t;
  } else {
    mSize -= a;
  }
}

#endif
