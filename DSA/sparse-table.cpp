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

const int N = 1e5 + 3;
const int LG = 20;
int sp[LG][N];


void solve() {
  int n; cin >> n;
  for(int i=0; i<n; ++i) cin >> sp[i][0];

  for(int i=1; i<21; ++i) {
    for(int j=0; j+(1<<i)-1<n; ++j) {
      sp[j][i] = min(sp[j][i-1], sp[j+(1<<(i-1))][i-1]);
    }
  }

  int q; cin >> q;
  while(q--) {
    int l, r; cin >> l >> r;
    int lg = log2(r-l+1);
    cout << min(sp[l][lg], sp[r-(1<<lg)+1][lg]) << ln;
  }
  return ;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC; 
  while(TC--) solve();
  return 0;
}
