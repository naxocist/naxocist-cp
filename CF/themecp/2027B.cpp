#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

void solve() {
  int n; cin >> n;
  vector<int> v(n); for(auto &x : v) cin >> x;

  int res = INT_MAX;
  for(int i=0; i<n; ++i) {
    int cnt = 0;
    for(int j=i+1; j<n; ++j) cnt += v[j] > v[i];

    res = min(res, cnt+i);
  }

  cout << res << ln;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int T; cin >> T; while(T--) solve();
  return 0;
}
