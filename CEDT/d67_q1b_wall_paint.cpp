#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

const int M = 3e5 + 3;
pii ar[M];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  
  for(int i=0; i<2*m; ++i) {
    int x, c, d; cin >> x >> c >> d; c--;
    if(!d) ar[c].first = x;
    else ar[c].second = x;
  }

  int res = 1;
  set<pii> s;
  s.emplace(-1, 0);
  s.emplace(1e6 + 1, 0);

  vector<int> cnt(m + 1);
  for(int i=0; i<m; ++i) {
    auto [l, r] = ar[i];
    int d = i + 1;
    auto t = s.lower_bound({l, 0});

    auto [x, xt] = *prev(t);
    auto [y, yt] = *t;

    if(r < y) s.emplace(l, d), s.emplace(r, -d);

    cnt[d] = cnt[xt] + 1;
    res = max(res, cnt[d]);
    // if(xt >= 0) {
    // }else {
    //
    // }
  }

  cout << res;

  return 0;
}

