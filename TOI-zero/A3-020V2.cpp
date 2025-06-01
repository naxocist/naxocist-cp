#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int h1, h2, b1, b2; cin >> h1 >> h2 >> b1 >> b2;
  int x, y; cin >> x >> y;

  int mx_all_white = min({h1, b1, x});
  int res = 0;
  for(int i=0; i<=mx_all_white; ++i) {
    int mx_all_black = min({h2, b2, x-i});
    for(int j=0; j<=mx_all_black; ++j) {
      int h1b2 = min(h1-i, b2-j);
      int h2b1 = min(h2-j, b1-i);
      res = max(res, i + j + min(h1b2+h2b1, y));
    }
  }

  cout << res;
}
