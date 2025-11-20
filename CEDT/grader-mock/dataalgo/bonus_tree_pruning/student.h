#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "map_bst.h"
#include <algorithm>
using namespace std;

#define all(x) x.begin(), x.end()

// this is the modify() function to be submitted
template <typename KeyT, typename MappedT, typename CompareT>
void CP::map_bst<KeyT, MappedT, CompareT>::modify(
    CP::map_bst<KeyT, MappedT, CompareT> &other) {

  if (other.mRoot == NULL) return;

  KeyT otherKey = other.mRoot->data.first;

  if (mRoot == NULL) {
    mRoot = other.mRoot;
    mSize = other.mSize;
  } else if(mRoot->data.first == otherKey) {
    if(mRoot->left != NULL or mRoot->right != NULL) return ;
    mRoot = other.mRoot;
    mSize = other.mSize;
  }
  else {

    auto vec = getValuesInorder();
    auto lw = lower_bound(all(vec), otherKey);
    auto up = upper_bound(all(vec), otherKey);

    int state = 0;
    if(lw == vec.begin()) state = 1; // no left, so only right
    else lw = prev(lw);
    if(up == vec.end()) state = -1; // no right, so only left

    auto old_sz = mSize;
    graft(mRoot, other.mRoot, other.mSize);

    if (old_sz != mSize) {
      mSize -= prune(other.mRoot, *up, *lw, state, 0);
    }
  }

  other.mRoot = NULL;
  other.mSize = 0;
  return;
}

// you may use this function to traverse and graft
template <typename KeyT, typename MappedT, typename CompareT>
void CP::map_bst<KeyT, MappedT, CompareT>::graft(
    CP::map_bst<KeyT, MappedT, CompareT>::node *n,
    CP::map_bst<KeyT, MappedT, CompareT>::node *m, size_t otherSize) {
  if (n == NULL)
    return;

  KeyT key = n->data.first, otherKey = m->data.first;
  if (key == otherKey) {
    if (n->left != NULL or n->right != NULL) return;

    if(mLess(key, n->parent->data.first)) n->parent->left = m;
    else n->parent->right = m;
    m->parent = n->parent;

    mSize += otherSize - 1;
    return;
  }

  if (mLess(otherKey, key)) {
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

// you may use this function to traverse and prune
template <typename KeyT, typename MappedT, typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::prune(
    CP::map_bst<KeyT, MappedT, CompareT>::node *n, KeyT r, KeyT l, int state,
    int gone) {
  if (n == NULL) return 0;
  if (gone) return prune(n->left, r, l, state, gone) + prune(n->right, r, l, state, gone) + 1;
  /*
  state:
    -1  = only left bound
     0  = both bound
     1  = only right bound
  */
  bool violate = 0;
  KeyT key = n->data.first;
  if(state == 0 or state == -1) {
    // !(l < key) = (key <= l)
    violate = !mLess(l, key);
  }

  if(state == 0 or state == 1) {
    // !(key < r) = (key >= r)
    violate = violate or !mLess(key, r);
  }

  if(violate) {
    if(mLess(key, n->parent->data.first)) n->parent->left = NULL;
    else n->parent->right = NULL;
    n->parent = NULL;
    return prune(n->left, r, l, state, 1) + prune(n->right, r, l, state, 1) + 1;
  }

  return prune(n->left, r, l, state, gone) + prune(n->right, r, l, state, gone);
}

#endif
