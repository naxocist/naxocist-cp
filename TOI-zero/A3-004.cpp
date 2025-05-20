#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back


int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;

  vector<int> a(n), b(n);
  using pi = pair<int, int>;
  vector<pi> p;
  for(int i=0; i<n; ++i) {
    int x, y; cin >> x >> y; a[i] = x-y, b[i] = x+y;
    p.pb(a[i],b[i]);
  }
  sort(all(a)); sort(all(b));

  pi t;
  if(n&1) {
    t = {a[n/2], b[n/2]};
  }else {
    t = {a[n/2 - 1], b[n/2 - 1]};
  }

  ll res = 0;
  for(auto [c1, c2] : p) {
    res += abs(c1 - t.first) + abs(c2 - t.second);
  }
  cout << res;

  return 0;
}
