#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "map_bst.h"
using std::cout;
template <typename KeyT, typename MappedT, typename CompareT>
void CP::map_bst<KeyT, MappedT, CompareT>::modify(
    CP::map_bst<KeyT, MappedT, CompareT> &other) {

  if (other.mRoot == NULL)
    return;

  if (mRoot == NULL) {
    mRoot = other.mRoot;
    mSize = other.mSize;
  } else {
    graft(mRoot, other.mRoot, other.mSize);
  }

  other.mRoot = NULL;
  other.mSize = 0;
  return;
}

// you may use this function to find the grafting point
template <typename KeyT, typename MappedT, typename CompareT>
void CP::map_bst<KeyT, MappedT, CompareT>::graft(
    CP::map_bst<KeyT, MappedT, CompareT>::node *n,
    CP::map_bst<KeyT, MappedT, CompareT>::node *m, size_t otherSize) {

  if (n == NULL) return;
  if (n->data == m->data) {
    if (n->left != NULL or n->right != NULL) return;
    n->left = m->left;
    n->right = m->right;
    mSize += otherSize - 1;
    return;
  }

  if (mLess(m->data.first, n->data.first)) {
    if (n->left == NULL) {
      n->left = m;
      mSize += otherSize;
      return;
    }
    graft(n->left, m, otherSize);
  } else {
    if (n->right == NULL) {
      n->right = m;
      mSize += otherSize;
      return;
    }
    graft(n->right, m, otherSize);
  }
  return;
}

#endif
