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
  int n; cin >> n; vector<int> v(n); for(auto &x : v) cin >> x;
  sort(all(v));

  pv(v);

  // find the first value that is >= k [FFFTTTT]
  int k; cin >> k;
  int l = -1, r = n;
  while(l + 1 < r) {
    int m = l + (r-l)/2;
    if(v[m] >= k) r = m;
    else l = m;
  }
  if(r == n) cout << "No value that is >= " << k << ln;
  else cout << v[r] << " is the first value that >= " << k << ln;

  // find the last value that is <= t [TTTTFFFF]
  int t; cin >> t;
  l = -1, r = n;
  while(l + 1 < r) {
    int m = l + (r-l)/2;
    if(v[m] <= k) l = m;
    else r = m;
  }

  if(l == -1) cout << "No value that is <= " << t << ln;
  else cout << v[l] << " is the last value that is <= " << t << ln;


  // find the value of sqrt(x);
  double x; cin >> x;

  double dl = 0, dr = x, eps = 1e-10;
  while(dr-dl > eps) {
    double m = dl + (dr-dl)/2;
    if(m*m >= x) dr = m;
    else dl = m;
  }
  cout << "The sqrt of " << x << " is " << dr << ln;
  return ;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC; 
  while(TC--) solve();
  return 0;
}
