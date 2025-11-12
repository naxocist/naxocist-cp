#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"
using std::cout;

template <typename T>
void CP::queue<T>::block_insert(size_t p, size_t m, const T &element)
{
  ensureCapacity(mSize + m);

  if(2*p < mSize) {
    for(int i=0; i<p; ++i) {
      size_t idx = (mFront + i + mCap) % mCap;
      size_t nw = (mFront - m + i + mCap) % mCap;
      mData[nw] = mData[idx];
    }

    for(int i=0; i<(int)m; i++) {
      size_t nw = (mFront - m + p + i + mCap) % mCap;
      mData[nw] = element;
    }
    mFront = (mFront - m + mCap) % mCap;
  }else {
    for(int i=mSize-1; i>=(int)p; i--) {
      size_t idx = (mFront + i + mCap) % mCap;
      size_t nw = (mFront + i + m) % mCap;
      mData[nw] = mData[idx];
    }

    for(int i=0; i<(int)m; i++) {
      size_t idx = (mFront + p + i + mCap) % mCap;
      mData[idx] = element;
    }

  }

  mSize += m;
}

#endif
