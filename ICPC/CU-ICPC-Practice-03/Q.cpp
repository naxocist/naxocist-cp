#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 1e6 + 1;

int fw[N];

void upd(int i, int x) {
  for(;i<N;i+=i&-i) fw[i] += x;
}

int qry(int i) {
  int s = 0;
  for(;i>0;i-=i&-i) s += fw[i];
  return s;
}

int bin(int idx) {

  int l = 0, r = 1e6 + 1;
  while(l + 1 < r) {
    int m = l + (r-l)/2;
    if(qry(m) >= idx) r = m;
    else l = m;
  }

  return r;
}


int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, q; cin >> n >> q;

  for(int i=0; i<n; ++i) {
    int x; cin >> x;
    upd(x, 1);
  }

  while(q--) {
    int x; cin >> x;
    if(x > 0) upd(x,1);
    else upd(bin(abs(x)),-1);
  }

  for(int i=1; i<=n; ++i) {
    if(qry(i)-qry(i-1)) cout << i, exit(0);
  }
  cout << 0;
  return 0;
}
