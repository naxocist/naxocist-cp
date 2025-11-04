#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "vector.h"
#include "algorithm"


template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {

  sort(data.begin(), data.end());
  int crr = 0;

  int nwSize = mSize + (int)data.size();
  T *arr = new T[nwSize]();
  int used_data = 0;

  for(int i=0; i<nwSize; ++i) {
    auto &[pos, v] = data[crr];
    if(pos+crr == i) {
      arr[i] = v;
      crr ++;
    }else {
      arr[i] = mData[i-crr];
    }
  }

  delete [] mData;
  mData = arr;
  mSize = nwSize;
  mCap = nwSize;
}

#endif
