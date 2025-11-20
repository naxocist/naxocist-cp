
#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "list.h"
using std::cout;

template <typename T> void CP::list<T>::zigzag(CP::list<T> &ls) {
  /*

      “In war, then, let your great object be victory, not lengthy campaigns.”
      ― Sun Tzu, The Art of War

  */

  node *a = mHeader->next;
  node *b = ls.mHeader->next;
  while(a != mHeader and b != ls.mHeader){
    node *na = a->next;
    node *nb = b->next;
    a->next = b;
    b->prev = a;

    b->next = na;
    na->prev = b;

    a = na;
    b = nb;
  }

  if(a == mHeader and b != ls.mHeader) {
    node *h = a;
    node *ph = a->prev;
    ph->next = b;
    b->prev = ph;

    while(b->next != ls.mHeader) b = b->next;
    b->next = h;
    h->prev = b;
  }

  mSize += ls.mSize;
  ls.mHeader->next = ls.mHeader;
  ls.mHeader->prev = ls.mHeader;
  ls.mSize = 0;
}
#endif
