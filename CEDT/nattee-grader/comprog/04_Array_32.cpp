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
  int s[n], t[n], no[n];
  for(int i=0; i<n; ++i) cin >> no[i] >> s[i] >> t[i];

  int q; cin >> q;
  while(q--) {
    int a, b; cin >> a >> b;

    int mn = INT_MAX, idx = -1;
    for(int i=0; i<n; ++i) {
      int x = s[i], y = t[i];
      int c = 0;
      if(min(x, y) <= a && a <= max(x, y)) {
        if(a == b) c = 0;
        else if(x < y) {
          if(a < b)  c = max(0, b-y);
          else c = y - b;
        }else {
          if(b < a) c = max(0, y-b);
          else c = b - y;
        }
      }else {
        c = abs(a - y) + abs(a - b);
      }

      if(c < mn) mn = c, idx = no[i];
      else if(c == mn) idx = min(idx, no[i]);
    }

    cout << ">> " << idx << ln;
  }
  return 0;
}

