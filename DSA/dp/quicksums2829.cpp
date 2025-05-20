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
#define p2(x) cout << #x << " = {" << x.first << ',' << x.second << "}\n";
#define pv(a) cout << #a << " = "; for(auto _x : a) cout << _x << ' '; cout << '\n';
#define pv2(a) cout << #a << " = "; for(auto [_x,_y] : a)cout << '{' << _x << ',' << _y << "} "; cout << '\n';
#define pa(a,n) cout << #a << " = "; for(int _i = 1; _i <= n; ++_i)cout << a[_i] << ' '; cout << '\n';
#define pa0(a,n) cout << #a << " = "; for(int _i = 0; _i < n; ++_i)cout << a[_i] << ' '; cout << '\n';

#define INF 2e9
#define LINF 2e18
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int a, int b) { return uniform_int_distribution<int>(a,b)(rng);}
ll uld(ll a, ll b) { return uniform_int_distribution<ll>(a,b)(rng); } 

int dp[10][10][103];

void solve() {
  string s; int k; cin >> s >> k;

  int n = s.size();
  for(int sz=1; sz<=n; ++sz) {
  	for(int l=0; l<n; ++l) {
			int r = l + sz - 1;
  		if(r >= n) break ;

  		for(int h=0; h<=100; ++h) {
  			if(sz == 1) {
  				dp[l][r][h] = (h == (s[l]-'0') ? 0 : INF);
  				continue ;
  			}
  			dp[l][r][h] = INF;
  			for(int k=l; k<r; ++k) {
  				for(int g=0; g<=h; ++g) {
  					if(dp[l][k][g] != INF and dp[k+1][r][h-g] != INF)
  						dp[l][r][h] = min(dp[l][r][h], dp[l][k][g] + dp[k+1][r][h-g] + 1);
  				}
  			}
  		}

  		if(sz > 9) continue ;
  		int t = stoi(s.substr(l,sz));
  		if(t <= 100) dp[l][r][t] = 0;
  	}
  }

  int res = dp[0][n-1][k];
  if(res == INF) res = -1;
  cout << res;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC; 
  while(TC--) solve();
  return 0;
}
