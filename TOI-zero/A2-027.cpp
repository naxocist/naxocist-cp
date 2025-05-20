#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n; vector<int> v(n); for(auto &x : v) cin >> x;
  int c = 0, mx = *max_element(all(v));
  for(auto x : v) c += x == mx;
  cout << mx << ln << c;
  return 0;
}
