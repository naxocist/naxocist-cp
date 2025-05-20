#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, k; cin >> n >> k;
  int mn = INT_MAX;
  vector<int> v(n); for(auto &x : v) cin >> x, mn = min(mn, x);

  ll res = 0;
  for(auto x : v) if(1ll*(k-1)*(x-mn) < mn) res ++ ;
  
  cout << res;
  return 0;
}
