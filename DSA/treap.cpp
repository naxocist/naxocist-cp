#include <bits/stdc++.h>
using namespace std;

mt19937 rng(time(0));

struct node {
  int key, pr, cnt;
  node *l, *r;
  node(int k) : key(k), pr(rng()), l(nullptr), r(nullptr), cnt(0) {}
};

using pnode = node*;

int cnt(pnode t) { return t ? t->cnt : 0; }
void upd_cnt(pnode t) { if (t) t->cnt = cnt(t->l) + 1 + cnt(t->r); }


void split(pnode t, pnode &l, pnode &r, int k) {
  if (!t) return void(l = r = nullptr);

  if (cnt(t->l) + 1 <= k) split(t->r, t->r, r, k - cnt(t->l) - 1), l = t;
  else split(t->l, l, t->l, k), r = t;

  upd_cnt(t);
}

void insert(pnode &t, int x) { return ; }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  pnode t; int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
  }
}
