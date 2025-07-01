#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n; 
  int s = 0, k = n, mx = -INT_MAX, mn = INT_MAX;
  while(n--) {
    int x; cin >> x; s += x; mx = max(mx, x), mn = min(mn, x);
  }

  cout << mx << ln << mn << ln << fixed << setprecision(2) << (double)s/k;
  return 0;
}