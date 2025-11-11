#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <algorithm>
#include "queue.h"

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{

  sort(pos.begin(), pos.end());
  int c = 0, j = 0;
  for(int i=0; i<mSize; ++i) {
    while(j == pos[c]) c++, j++;
    mData[(mFront + i) % mCap] = mData[(mFront + j) % mCap];
    j ++;
  }
  mSize -= pos.size();
}

#endif
