void splitList(list<T>& list1, list<T>& list2) {
  int n = (size() + 1)/2;
  int m = size()/2;

  if(n == 0) return ;

  node *back1 = mHeader;
  for(int i=0; i<n; ++i)  {
    back1 = crr->next;
  }
  node *front2 = crr->next;

  list1.mHeader->prev->next = mHeader->next;
  mHeader->next->prev = list1.mHeader->prev;
  back1->next = list1.mHeader;
  list1.mHeader->prev = crr;

  list2.mHeader->prev->next = crr2;
  front2->prev = list2.mHeader->prev;
  mHeader->prev->next =  list2.mHeader;
  list2.mHeader->prev = mHeader->prev;

  mHeader->prev = mHeader;
  mHeader->next = mHeader;

  mSize = 0;
  list1.mSize += n;
  list2.mSize += m;
}
