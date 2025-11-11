int res = -1, mx = -1;
int f(node *r) {
  if(r == NULL) return 0;
  int hl = f(r->left);
  int hr = f(r->right);
  int d = abs(hl - hr);

  int val = r->data.first;
  if(d > mx) mx = d, res = val;
  else if(d == mx and val < res) res = val;
  return std::max(hl, hr) + 1;
}

KeyT getValueOfMostImbalanceNode() {
  f(mRoot);
  return res;
}
