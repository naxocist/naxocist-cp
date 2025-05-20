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

using T = tuple<ll, int, int>;
const int N = 2e5 + 3;
vector<pii> adj[N];
bool vis[N][2];

void solve() {
  int n, m, x; cin >> n >> m >> x;
  for(int i=0; i<m; ++i) {
    int u, v; cin >> u >> v;
    adj[u].pb(v, 0); adj[v].pb(u, 1);
  }

  priority_queue<T, vector<T>, greater<T>> pq;
  pq.emplace(0, 1, 0);
  while(pq.size()) {
    auto [d, u, s] = pq.top(); pq.pop();
    if(u == n) {
      cout << d << ln; return ;
    }
    if(vis[u][s]) continue ;
    vis[u][s] = 1;

    for(auto [v, b] : adj[u]) {
      if(s == b) pq.emplace(d + 1, v, s);
      else pq.emplace(d + x + 1, v, s^1);
    }
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
