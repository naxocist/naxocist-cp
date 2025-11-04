#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"

template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  int c = 0;
  for(auto &x : pos) {
    erase(this->begin() + x - c++);
  }
}

#endif
