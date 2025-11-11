#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT, typename MappedT, typename CompareT>
CP::map_bst<KeyT, MappedT, CompareT>
CP::map_bst<KeyT, MappedT, CompareT>::split(KeyT val) {
  CP::map_bst<KeyT, MappedT, CompareT> result;
  
  node *crr = mRoot;
  node *lRoot = NULL;
  node *lConnect = NULL;
  node *gteRoot = NULL;
  node *gteConnect = NULL;

  while (crr != NULL) {
    if (crr->data.first >= val) {
      if(gteRoot == NULL) gteRoot = crr;

      if(crr->parent) crr->parent->right = NULL;
      crr->parent = NULL;

      if(gteConnect) {
        gteConnect->left = crr;
        crr->parent = gteConnect;
      }

      node *go = crr;
      while (go != NULL and go->data.first >= val) go = go->left;

      gteConnect = go ? go->parent : NULL;
      if(go) go->parent->left = NULL, go->parent = NULL;
      crr = go;

    }else {
      if(lRoot == NULL) lRoot = crr;
      if(lConnect) {
        lConnect->right = crr;
        crr->parent = lConnect;
      }
      lConnect = crr;
      crr = crr->right;
    }
  }

  mRoot = lRoot;
  result.mRoot = gteRoot;
  return result;
}

#endif
