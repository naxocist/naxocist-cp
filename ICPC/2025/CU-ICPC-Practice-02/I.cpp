#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

void solve() {
  int n; cin >> n;
  vector<ll> v(n); for(auto &x : v) cin >> x;
  sort(all(v));
  
  ll res = v[0]*v[n-1];
  vector<ll> t;
  for(ll i=2; i*i<=res; ++i) {
    if(res%i) continue ;
    t.pb(i);
    if(res/i != i) t.pb(res/i);
  }
  sort(all(t));

  if(v != t) cout << -1;
  else cout << res;
  cout << ln;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int T; cin >> T;
  while(T--) solve();
  return 0;
}