#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "vector.h"
#include <algorithm>

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  size_t la = a - begin(); 
  size_t lb = b - begin();
  size_t ra = la + m - 1;
  size_t rb = lb + m - 1;

  if(m <= 0 || la < 0 || lb < 0 || ra >= mSize || rb >= mSize || la >= mSize || lb >= mSize) return false;
  if(ra >= lb && la <= rb) return false;

  while(m --) {
    std::swap(mData[la++], mData[lb++]);
  }

  return true;

}

#endif
