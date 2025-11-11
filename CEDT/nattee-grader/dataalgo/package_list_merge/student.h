#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>
#include "list.h"

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {


  node *origin_mHeader = mHeader;
  node *back = mHeader->prev;


  for(auto it=ls.begin(); it != ls.end(); ++it) {
    if(it->mSize == 0) continue ;

    it->mHeader->next->prev = back;
    back->next = it->mHeader->next;
    mSize += it->mSize;

    back = it->mHeader->prev;
    back->next = origin_mHeader;
    origin_mHeader->prev = back;

    it->mHeader->next = it->mHeader;
    it->mHeader->prev = it->mHeader;
    it->mSize = 0;
  }
}

#endif
