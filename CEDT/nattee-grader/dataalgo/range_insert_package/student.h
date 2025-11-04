#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "vector.h"

template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  while(first != last) {
    position = insert(position, *first);
    first ++;
  }
}

#endif
