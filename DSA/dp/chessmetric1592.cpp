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

const int N = 1e2 + 3;
ll dp[51][N][N];

void solve() {
  int n, a, b, c, d; cin >> n >> a >> b >> c >> d; 
  int k; cin >> k;

  int tr[] = {-1, -1, -1, 0, 0, 1, 1, 1}, tc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
  int gr[] = {-1, -2, -2, -1, 1, 2, 2, 1}, gc[] = {-2, -1, 1, 2, 2, 1, -1, -2}; 

  auto ok = [&](int i, int j) {
    return i >= 0 and i < n and j >= 0 and j < n;
  };

  dp[0][a][b] = 1;
  for(int m=1; m<=k; ++m) {
    for(int i=0; i<n; ++i) {
      for(int j=0; j<n; ++j) {
        for(int h=0; h<8; ++h) {
          int ii = i + tr[h], jj = j + tc[h]; if(!ok(ii, jj)) continue ;
          dp[m][i][j] += dp[m-1][ii][jj];
        }
        for(int h=0; h<8; ++h) {
          int ii = i + gr[h], jj = j + gc[h]; if(!ok(ii, jj)) continue ;
          dp[m][i][j] += dp[m-1][ii][jj];
        }
      }
    }
  }
  cout << dp[k][c][d] << ln;
  return ;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC; 
  while(TC--) solve();
  return 0;
}
