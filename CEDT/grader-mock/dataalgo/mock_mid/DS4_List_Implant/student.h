#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "list.h"
using std::cout;
template <typename T>
void CP::list<T>::implant(CP::list<T> &other, int pos1, int pos2, int count) {
  if (count == 0) return;

  node *crr = mHeader->next;
  while(pos1--) crr = crr->next;

  node *x = other.mHeader->next;
  while(pos2--) x = x->next;
  node *y = x;
  int k = count;
  while(--k) y = y->next;

  x->prev->next = y->next;
  y->next->prev = x->prev;

  node *ed = crr->next;
  crr->next = x;
  x->prev = crr;

  y->next = ed;
  ed->prev = y;

  mSize += count;
  other.mSize -= count;
}
#endif

