#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

using pi = pair<int, int>;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, L; cin >> n >> L;
  vector<pi> v(n); for(auto &[a, b] : v) cin >> a >> b;
  sort(all(v));

  int cl = -1, cr = -1, res = 0;
  for(auto [l, r] : v) {
    if(l <= cr) cl = max(cl, l), cr = min(cr, r); 
    else res++, cl = l, cr = r;
  }

  cout << res;
  return 0;
}
