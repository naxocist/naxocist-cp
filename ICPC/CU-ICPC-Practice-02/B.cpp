#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m, k; cin >> n >> m >> k;
  vector<int> v(m); for(auto &x : v) cin >> x;

  int x; cin >> x;

  int res = 0;
  for(auto y : v) {
    y ^= x;
    if(__builtin_popcount(y) <= k) res ++;
  }
  cout << res;
  return 0;
}