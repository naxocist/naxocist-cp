#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;

  vector<double> v(n); 
  ll s = 0;
  for(auto &x : v) {
    cin >> x;
    s += floor(x);
  }

  s = abs(s);
  for(auto x : v) {
    if(x != ceil(x) and s-- > 0) cout << (int)ceil(x);
    else cout << (int)floor(x);
    cout << ln;
  }
  return 0;
}