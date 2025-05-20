#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n; 
  vector<int> v(n); for(auto &x : v) cin >> x;
  sort(all(v));

  int s = 0, res = 0;
  for(auto x : v) s += x, res += 2*s;
  cout << res;
  return 0;
}
