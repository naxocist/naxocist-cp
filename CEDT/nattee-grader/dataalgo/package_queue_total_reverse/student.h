#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
#include "queue.h"

template <typename T> void CP::queue<T>::reverse() {
  if(aux) mFront = mFront - mSize + 1;
  else mFront = mFront + mSize - 1;
  mFront += mCap, mFront %= mCap;
  aux = !aux;
}

template <typename T> const T &CP::queue<T>::front() const {
  return mData[mFront];
}

template <typename T> const T &CP::queue<T>::back() const {
  if(aux) return mData[(mFront - mSize + 1 + mCap) % mCap];
  return mData[(mFront + mSize - 1 + mCap) % mCap];
}

template <typename T> void CP::queue<T>::push(const T &element) {
  if(mSize + 1 > mCap) {
    T *ar = new T[2*mCap]();
    for(int i=0; i<mSize; ++i) {
      if(aux) ar[i] = mData[(mFront - mSize + 1 + i + mCap) % mCap];
      else ar[i] = mData[(mFront + i) % mCap];
    }

    delete []mData;
    mData = ar;
    mCap *= 2;
    mFront = aux ? mSize - 1 : 0;
  }

  if(aux) mData[(mFront - mSize + mCap) % mCap] = element;
  else mData[(mFront + mSize) % mCap] = element;
  mSize ++;
}

template <typename T> void CP::queue<T>::pop() {
  if(aux) mFront --;
  else mFront ++;
  mFront += mCap, mFront %= mCap;
  mSize--;
}

#endif
