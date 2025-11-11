#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

using std::max;
template <typename KeyT, typename MappedT, typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node *n, int &res) {
  if(n == NULL) return 0;
  if(n->left == NULL and n->right == NULL) return 1;

  int hl = my_recur(n->left, res);
  int hr = my_recur(n->right, res);
  res = max(res, hl + hr);

  return max(hl, hr) + 1;
}

template <typename KeyT, typename MappedT, typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {
  int res = mSize == 1 ? 0 : -1;
  my_recur(mRoot, res);

  return res;
}

#endif
