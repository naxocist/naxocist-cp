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
  int X1[n], Y1[n], X2[n], Y2[n];
  for(int i=0; i<n; ++i) {
    cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
  }

  int mx = -1;
  for(int i=0; i<n; ++i) {
    int a = X1[i], b = Y1[i], c = X2[i], d = Y2[i];
    for(int j=i+1; j<n; ++j) {
      int x = X1[j], y = Y1[j], p = X2[j], q = Y2[j];

      int dx = min(c, p) - max(a, x), dy = min(d, q) - max(b, y);
      if(dx < 0 or dy < 0) continue ;
      mx = max(mx, dx*dy);
    }
  }

  if(mx <= 0) cout << "No overlaps", exit(0);

  cout << "Max overlapping area = " << mx << ln;
  for(int i=0; i<n; ++i) {
    int a = X1[i], b = Y1[i], c = X2[i], d = Y2[i];
    for(int j=i+1; j<n; ++j) {
      int x = X1[j], y = Y1[j], p = X2[j], q = Y2[j];

      int dx = min(c, p) - max(a, x), dy = min(d, q) - max(b, y);
      if(dx < 0 or dy < 0) continue ;
      if(dx*dy == mx) cout << "rectangles " << i << " and " << j << ln;
    }
  }
  return 0;
}

