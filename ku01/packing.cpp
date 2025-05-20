#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m, l, r; cin >> m >> n >> l >> r;

  int res = INT_MAX;
  for(int i=l; i<=min({n, m, r}); ++i) {
  	res = min(res, (m%i)*(n%i));
  }

  if(res == INT_MAX) res = 0;
  cout << res;
  return 0;
}
