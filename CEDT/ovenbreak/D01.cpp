#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  double s = 0;
  vector<int> v(n); for(auto &x : v) cin >> x, s += x;
  s /= n;

  double mx = 0;
  int res = 0;
  for(auto x : v)  {
    if(abs(s-x) > mx) {
      mx = abs(s-x);
      res = x;
    }
  }

  cout << res;
  return 0;
}