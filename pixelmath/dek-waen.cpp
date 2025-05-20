#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define pil pair<int, ll>
#define pli pair<int, ll>
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

using T = tuple<int, ll, int>;
const int N = 555;
const ll INF = LLONG_MAX;
ll d[N][N];

void solve() {
	int n, m, k; cin >> n >> m >> k;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			if(i == j) continue ;
			d[i][j] = INF;
		}
	}

	vector<tuple<ll, int, int, int>> edge;
	for(int i=0; i<m; ++i) {
		int u, v; ll w; cin >> u >> v >> w; u--, v--;
		d[u][v] = d[v][u] = w;
		edge.pb(w, u, v, i);
	}

	for(int k=0; k<n; ++k) {
		for(int i=0; i<n; ++i) {
			for(int j=0; j<n; ++j) {
				if(d[i][k] == INF or d[k][j] == INF) continue ;
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	vector<tuple<int, int, ll>> q(k); for(auto &[a, b, x] : q) cin >> a >> b >> x, a--, b--;
	vector<bool> use(m);
	for(auto [w, u, v, id] : edge) {
		for(auto [a, b, x] : q) {
			if(d[a][u] != INF and d[v][b] != INF and d[a][u] + w + d[v][b] <= x) use[id] = 1;
			if(d[a][v] != INF and d[u][b] != INF and d[a][v] + w + d[u][b] <= x) use[id] = 1;

			if(use[id]) break ;
		}
	}

	int res = 0;
	for(auto u : use) res += u;
	cout << res;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC; 
  while(TC--) solve();
  return 0;
}
