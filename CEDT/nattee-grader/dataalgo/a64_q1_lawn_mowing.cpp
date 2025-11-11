#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q; ll k; cin >> n >> q >> k;
  vector<ll> v(n + 1);

  for(int i=1; i<=n; ++i) {
    cin >> v[i];
    v[i] += v[i-1];
  }

  while(q --) {
    int L; ll p; cin >> L >> p; L ++;

    int l = L-1, r = n + 1;
    while(l + 1 < r) {
      int m = l + (r-l)/2;

      ll qs = v[m] - v[L-1], len = m-L+1;
      if(qs + len*k <= p) l = m;
      else r = m;
    }

    if(l == L-1) cout << 0;
    else cout << v[l] - v[L-1];
    cout << '\n';
  }
  return 0;
}
