#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define pll pair<ll, ll>
#define all(x) x.begin(), x.end()
#define pb emplace_back
#define p(x) cout << #x << " = " << x << '\n';
#define p2(x) cout << #x << " = {" << x.first << ',' << x.second << "}\n";
#define pv(a) cout << #a << " = "; for(auto _x : a) cout << _x << ' '; cout << '\n';
#define pv2(a) cout << #a << " = "; for(auto [_x,_y] : a)cout << '{' << _x << ',' << _y << "} "; cout << '\n';
#define pa1(a,n) cout << #a << " = "; for(int _i = 1; _i <= n; ++_i)cout << a[_i] << ' '; cout << '\n';
#define pa0(a,n) cout << #a << " = "; for(int _i = 0; _i < n; ++_i)cout << a[_i] << ' '; cout << '\n';

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int a, int b) { return uniform_int_distribution<int>(a,b)(rng);}
ll uld(ll a, ll b) { return uniform_int_distribution<ll>(a,b)(rng); } 

void solve() {
  int n; cin >> n;
  vector<int> v(n);
  for(auto &x : v) cin >> x;

  vector<bool> a(n), res(n);
  
  int mn = INT_MAX;
  for(int i=0; i<n; ++i) {
    mn = min(mn, v[i]);
    a[i] = mn == v[i];
  }

  int mx = INT_MIN;
  for(int j=n-1; j>=0; --j) {
    mx = max(mx, v[j]);
    res[j] = a[j] or mx == v[j];
  }
  for(auto x : res) cout << x;
  cout << ln;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  cin >> TC;
  while(TC--) solve();
  return 0;
}
