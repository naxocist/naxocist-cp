void shift(int k) {

  node *crr = mHeader->next;

  node *first = mHeader->next;
  node *last = mHeader->prev;
  last->next = first;
  first->prev = last;

  if(k > 0) {
    for(int i=0; i<k; ++i) crr = crr->next;
  }else {
    k = -k;
    for(int i=0; i<k; ++i) crr = crr->prev;
  }

  mHeader->prev = crr->prev;
  crr->prev->next = mHeader;

  mHeader->next = crr;
  crr->prev = mHeader;
}
