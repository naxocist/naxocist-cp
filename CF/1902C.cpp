#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double
#define all(x) begin(x), end(x)
#define pb emplace_back

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int a, int b) { return uniform_int_distribution<int>(a,b)(rng);}
ll uld(ll a, ll b) { return uniform_int_distribution<ll>(a,b)(rng); } 

void solve() {
  int n; cin >> n;
  ll mx = LLONG_MIN;

  vector<ll> v(n);
  set<ll> s;
  for(auto &x : v) cin >> x, mx = max(mx, x), s.insert(x);

  if(n == 1) {
    cout << 1 << ln;
    return ;
  }

  ll g = 0;
  for(auto x : v) g = __gcd(g, mx-x);

  ll res = 0;
  for(auto x : v) res += (mx-x)/g;

  for(int i=1; i<n; ++i) {
    if(s.find(mx-i*g) == s.end()) {
      cout << res + i << ln;
      return ;
    }
  }

  cout << res + n << ln;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  cin >> TC; 
  while(TC--) solve();
  return 0;
}

