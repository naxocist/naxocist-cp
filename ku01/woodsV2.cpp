#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back


int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, w, L; cin >> n >> w >> L;

  vector<int> h[n];
  for(int i=0; i<n; ++i) {
    int k; cin >> k;
    vector<int> v;
    v.pb(-2e9);
    while(k--) {
      int x; cin >> x; v.pb(x);
    }
    v.pb(2e9);

    h[i] = v;
  }

  for(int k=1; k<=w; ++k) {
    bool ok = 1;
    for(int i=0; i<n; ++i) {
      int x = *prev(upper_bound(all(h[i]), k));
      int y = *lower_bound(all(h[i]), k);
      if(k-x <= L or y-k <= L) continue ;
      ok = 0;
      break ;
    }

    if(ok) cout << 1, exit(0);
  }

  cout << 0;
  return 0;
}
