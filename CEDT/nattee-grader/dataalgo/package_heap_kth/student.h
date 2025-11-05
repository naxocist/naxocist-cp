#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {

  std::vector<T> v;
  for(int i=0; i<mSize && i + 1 < (1<<k); ++i) {
    v.emplace_back(mData[i]);
  }

  sort(v.begin(), v.end(), mLess);
  return v[(int)v.size() - k];
}

#endif
