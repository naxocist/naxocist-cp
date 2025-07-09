#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 3e3 + 1;
int ln[N], sd[N], hp[N];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int l, n; cin >> l >> n;

  for(int i=0; i<n; ++i) {
    int x, c, v; cin >> x >> c >> v;
    ln[i] = x;
    if(c == 1) sd[i] = v;
    else hp[i] = v;
  }

  int res = 0;
  for(int i=0; i<1<<n; ++i) {
    int a = 0, b = 0, c = 0;
    for(int j=0; j<n; ++j) {
      if(i & (1<<j)) {
        a += ln[j];
        b += sd[j];
        c += hp[j];
      }
    }

    if(a > l) continue ;
    res = max(min(b, c), res);
  }

  cout << res;

  return 0;
}
