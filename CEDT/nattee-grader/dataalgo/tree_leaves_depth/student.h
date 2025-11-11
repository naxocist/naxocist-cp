#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT, typename MappedT, typename CompareT>
long long CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, size_t aux) {
  if(n == NULL) return 0;
  if(n->left == NULL and n->right == NULL) return aux;
  long long sum = 0;
  if(n->left) sum += my_recur(n->left, aux + 1); 
  if(n->right) sum += my_recur(n->right, aux + 1);
  return sum;
}

template <typename KeyT, typename MappedT, typename CompareT>
long long CP::map_bst<KeyT, MappedT, CompareT>::sum_leaves_depth() {
  return my_recur(mRoot, 0);
}

#endif
