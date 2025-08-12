#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> a(n); for(auto &x : a) cin >> x;

    int res = 0;
    for(int i=0; i<n; ++i) {
      int x; cin >> x;
      res += max(0, a[i] - x);
    }

    res ++;
    cout << res << ln;
  }
  return 0;
}
