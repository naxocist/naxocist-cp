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

const int N = 33, M = 3e4 + 3;
ll ar[N];
ll dp[N][M], dp2[N][M], c[N][N];

void solve() {

  c[0][0] = c[1][0] = c[1][1] = 1;
  for(int i=2; i<N; ++i) {
    for(int j=0; j<=i; ++j) {
      c[i][j] = c[i-1][j] + c[i-1][j-1];
    }
  }

  unordered_map<int, int> mp;
  int n; cin >> n; for(int i=1; i<=n; ++i) cin >> ar[i], mp[ar[i]] ++;
  sort(ar+1, ar+n+1);

  // pa(ar, n);

  dp[0][0] = 1;
  for(int i=1; i<=n; ++i) {
    for(int j=3e4; j>=0; --j) {
      dp[i][j] = dp[i-1][j];
      if(j + ar[i] <= 3e4) dp[i][j + ar[i]] += dp[i][j];
    }
  }

  dp2[n+1][0] = 1;
  for(int i=n; i>=1; --i) {
    for(int j=3e4; j>=0; --j) {
      dp2[i][j] = dp2[i+1][j];
      if(j + ar[i] <= 3e4) dp2[i][j + ar[i]] += dp2[i][j];
    }
  }

  ll res = 0;
  int prv = -1;
  for(int i=1; i<=n; ++i) {
    if(ar[i] == prv) continue ;
    prv = ar[i];

    int cnt = mp[ar[i]];
    for(int k=1; k<=cnt; ++k) {
     for(int j=k*ar[i]; j<=3e4; ++j) {
      res += c[cnt][k] * dp[i-1][j-(k*ar[i])] * dp2[i+k][j];
     }
    }
  }

  cout << res;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC; 
  while(TC--) solve();
  return 0;
}
