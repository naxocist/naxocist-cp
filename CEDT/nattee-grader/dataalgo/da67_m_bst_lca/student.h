
#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "map_bst.h"

template <typename KeyT, typename MappedT, typename CompareT>
typename CP::map_bst<KeyT, MappedT, CompareT>::iterator
CP::map_bst<KeyT, MappedT, CompareT>::recursive(
    node *n, CP::map_bst<KeyT, MappedT, CompareT>::iterator p,
    CP::map_bst<KeyT, MappedT, CompareT>::iterator q) const {

  KeyT nv = n->data.first;
  if (mLess(nv, (*p).first) and mLess(nv, (*q).first)) {
    return recursive(n->right, p, q);
  }

  if (mLess((*p).first, nv) and mLess((*q).first, nv)) {
    return recursive(n->left, p, q);
  }

  return iterator(n);
}

template <typename KeyT, typename MappedT, typename CompareT>
typename CP::map_bst<KeyT, MappedT, CompareT>::iterator
CP::map_bst<KeyT, MappedT, CompareT>::lca(
    CP::map_bst<KeyT, MappedT, CompareT>::iterator p,
    CP::map_bst<KeyT, MappedT, CompareT>::iterator q) const {

  return recursive(mRoot, p, q);
}

#endif
