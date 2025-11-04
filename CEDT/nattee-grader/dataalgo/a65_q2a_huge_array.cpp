#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q; cin >> n >> q;

  vector<pair<int, int>> vc;
  for(int i=0; i<n; ++i) {
    int x, c; cin >> x >> c;
    vc.emplace_back(x, c);
  }
  sort(vc.begin(), vc.end());

  vector<int> qs(n), val(n);
  for(int i=0; i<n; ++i) {
    auto [x, c] = vc[i];
    qs[i] = c; val[i] = x;
  }

  for(int i=1; i<n; ++i) {
    qs[i] += qs[i-1];
  }

  while(q--) {
    int k; cin >> k;
    int l = -1, r = n;
    while(l + 1 < r) {
      int m = l + (r-l)/2;
      if(qs[m] >= k) r = m;
      else l = m;
    }

    cout << val[r] << '\n';
  }
  return 0;
}
