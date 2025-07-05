#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  vector<int> v(n); for(auto &x : v) cin >> x;
  sort(all(v));

  int res = 0;
  for(int i=n-1; i>=0; --i) {
    if(m-- > 0) res ++;
    else res += v[i];
  }
  cout << res;
  return 0;
}