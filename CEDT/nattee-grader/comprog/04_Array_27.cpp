#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  int x[n], y[n]; for(int i=0; i<n; ++i) cin >> x[i] >> y[i];
  string m; cin >> m;

  int mn1 = INT_MAX, mx1 = INT_MIN, mn2 = INT_MAX, mx2 = INT_MIN;
  for(int i=0; i<n; ++i) {
    if(i&1^1) mn1 = min(mn1, x[i]), mx2 = max(mx2, y[i]), mx1 = max(mx1, x[i]), mn2 = min(mn2, y[i]);
    else mx2 = max(mx2, x[i]), mn1 = min(mn1, y[i]), mn2 = min(mn2, x[i]), mx1 = max(mx1, y[i]);
  }
  if(m == "Zig-Zag") cout << mn1 << ' ' << mx2;
  else cout << mn2 << ' ' << mx1;
  
  return 0;
}

