#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>
#include "map_bst.h"

// you can modify and use this function
template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::leaves_count(node* n) {
  if(n->left == NULL && n->right == NULL) return 1;

  int cnt = 0;
  if(n->left) cnt += leaves_count(n->left);
  if(n->right) cnt += leaves_count(n->right);
  return cnt;
}


template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::leaves_count() {
  return leaves_count(mRoot);
  //write your code here
}


#endif
