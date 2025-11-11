#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "map_bst.h"

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* ptr) const {
  if(ptr == NULL) return 0;
  int child = (ptr->left != NULL) + (ptr->right != NULL);
  return (child == 1) + process(ptr->left) + process(ptr->right);
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::count_unary() const {
  return process(mRoot);
}

#endif
