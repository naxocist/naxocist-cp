#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int m, k, a, b; cin >> m >> k >> a >> b;
  vector<int> x(1e3 + 1), h(1e3 + 1);

  for(int i=0; i<m; ++i) {
    int y, z; cin >> y >> z; x[y] = z;
  }

  for(int i=0; i<k; ++i) {
    int y, z; cin >> y >> z; h[y] = z;
  }

  for(int i=a; i<=b; ++i) {
    ll res = 0;
    for(int j=0; j<=1e3 and i-j >= 0; ++j) res += 1ll*x[j]*h[i-j];
    cout << res << ' ';
  }
  return 0;
}

