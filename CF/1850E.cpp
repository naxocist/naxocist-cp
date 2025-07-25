#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int q; cin >> q;
  while(q--) {
    int n; ll c; cin >> n >> c;
    ll area = 0;
    vector<ll> s(n); 
    for(auto &x : s) cin >> x, area += x*x;

    ll l = -1, r = 7e8 + 1;
    while(l + 1 < r) {
      ll md = l + (r-l)/2;

      ll sm = 0;
      for(auto x : s) {
        ll w = x+2*md;
        sm += w*w;
        if(sm >= c) {
          r = md;
          goto g;
        }
      }

      l = md;
      g:;
    }

    cout << r << '\n';
  }
  return 0;
}
