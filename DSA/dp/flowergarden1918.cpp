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
const int N = 53 ;
int h[N], l[N], r[N];

bool conflict(int i, int j) {
  return l[j] <= r[i] and l[i] <= r[j];
}

void solve() {
  int n; cin >> n;
  vector<pii> v;
  for(int i=1; i<=n; ++i) cin >> h[i], v.pb(h[i], i);
  for(int i=1; i<=n; ++i) cin >> l[i];
  for(int i=1; i<=n; ++i) cin >> r[i];

  sort(begin(v), end(v));
  vector<int> res;
  for(auto [_, i] : v) {
    int t = 0;
    for(int j=0; j<res.size(); ++j) {
      if(conflict(i, res[j])) t = j+1;
    }
    res.insert(begin(res)+t, i);
  }

  for(auto x : res) cout << h[x] << ' '; cout << ln;
  return ;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC; 
  while(TC--) solve();
  return 0;
}
