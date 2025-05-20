#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define all(x) begin(x), end(x)
#define pb emplace_back
#define dump(a) while(a.size())a.pop();
#define p(x) cout << #x << " = " << x << '\n';
#define p2(x) cout << #x << " = {" << x.f << ',' << x.s << "}\n";
#define pv(a) cout << #a << " = "; for(auto _x : a) cout << _x << ' '; cout << '\n';
#define pv2(a) cout << #a << " = "; for(auto [_x,_y] : a)cout << '{' << _x << ',' << _y << "} "; cout << '\n';
#define pa(a,n) cout << #a << " = "; for(int _i = 1; _i <= n; ++_i)cout << a[_i] << ' '; cout << '\n';
#define pa0(a,n) cout << #a << " = "; for(int _i = 0; _i < n; ++_i)cout << a[_i] << ' '; cout << '\n';

#define INF 2e9
#define LINF 2e18
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int a, int b) { return uniform_int_distribution<int>(a,b)(rng); }
ll uld(ll a, ll b) { return uniform_int_distribution<ll>(a,b)(rng); }


void solve() {
  int n, x; cin >> n >> x;
  vector<int> u(n), d(n); for(int i=0; i<n; ++i) cin >> u[i] >> d[i];

  auto ok = [&](ll h) {
    ll l = 0, r = h;
    for(int i=0; i<n; ++i) {
      ll nl = h - d[i], nr = u[i];
      nl = max(0ll, nl); nr = min(h, nr);
      l = max(nl, l-x), r = min(nr, r+x);
      if(l > r) return 0;
    }
    return 1;
  };

  ll l = -1, r = 2e10;
  while(l + 1 < r) {
    ll m = l + (r-l)/2;
    if(ok(m)) l = m;
    else r = m;
  }

  ll res = 0;
  for(int i=0; i<n; ++i) res += u[i] + d[i] - l;
  cout << res << ln;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC; 
  while(TC--) solve();
  return 0;
}
