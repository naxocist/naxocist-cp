#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;

  vector<ll> ar(n);
  for(auto &x : ar) cin >> x;
  sort(all(ar));
  ll a=0, b=0, pv = -1;
  for(auto x : ar) {
    if(pv == x) {
      pv = x; continue ;
    }
    pv = x;
    if(x > a) b=a,a=x;
    else if(x > b) b=x;
  }
  cout << b;
  return 0;
}