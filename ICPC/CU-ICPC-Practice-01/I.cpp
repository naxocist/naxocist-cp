#include <bits/stdc++.h>
using namespace std;

const int N = 1<<20;
int ar[N], seg[4*N];

void build(int i, int l, int r) {
  if(l == r) return void(seg[i] = ar[l]);
  int m = l + (r-l)/2;
  build(2*i,l,m); build(2*i+1,m+1,r);
  seg[i] = (int)log2(r-l+1) % 2 ? seg[2*i] | seg[2*i + 1] : seg[2*i] ^ seg[2*i + 1];
}

void upd(int i, int l, int r, int x, int v) {
  if(l == r) return void(seg[i] = v);
  int m = l + (r-l)/2;
  if(x <= m) upd(2*i,l,m,x,v);
  else upd(2*i+1,m+1,r,x,v);
  seg[i] = (int)log2(r-l+1) % 2 ? seg[2*i] | seg[2*i + 1] : seg[2*i] ^ seg[2*i + 1];
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m; cin >> n >> m;
  n = 1<<n;
  for(int i=1; i<=n; ++i) cin >> ar[i];
  build(1,1,n);

  while(m--) {
    int x, v; cin >> x >> v;
    upd(1,1,n,x,v);
    cout << seg[1] << '\n';
  }
  return 0;
}
