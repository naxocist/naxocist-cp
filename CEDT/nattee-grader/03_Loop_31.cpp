#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

ll f(ll a, ll b) {
  ll res = 1;
  for(int i=0; i < b; ++i) res *= a;
  return res;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  ll l, r; cin >> l >> r;

  ll res = 0;
  string s = to_string(l);
  string z = to_string(r);

  int n = s.size(), m = z.size();

  /*
  k digits - 100... - 999...

  1 digits = 1 - 9 = 9
  2 digits = 10 - 99 = 90
  3 digits = 100 - 999 = 900
  */

  if(n == m) {
    res += 1ll*(r-l+1)*n;
    cout << res;
    return 0;
  }

  for(int i=n+1; i<m; ++i) {
    res += (f(10, i) - f(10, i-1))*i;
  }

  res += (f(10, n) - l)*n;
  res += ((f(10, m) - f(10, m-1)) - (f(10, m) - r - 1))*m;

  cout << res;
  return 0;
}

