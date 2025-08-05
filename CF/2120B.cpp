#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 1e3 + 3;

void solve() {
  int n, s; cin >> n >> s;
  int res = 0;
  for(int i=0; i<n; ++i) {
    int d1, d2, x, y; cin >> d1 >> d2 >> x >> y;
    if(d1 == d2) res += x == y;
    else res += x + y == s;
  }

  cout << res << ln;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int T; cin >> T; while(T--) solve();
  return 0;
}
