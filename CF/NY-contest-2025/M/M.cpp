#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
const int N = 1e4 + 3;
using ll = long long;


int dsu[N], sz;
ll rad[N];

struct point {
	ll x, y;
	ll lvl;
} ar[N];

ll cost(point a, point b) {
	ll dx = a.x - b.x, dy = a.y - b.y;
	return dx*dx + dy*dy;
}

int par(int u) {
	return dsu[u] == u ? u : dsu[u] = par(dsu[u]);
}

void un(int u, int v) {
	u = par(u), v = par(v);
	if(u == v) return ;
	dsu[u] = v;
	sz -- ;
}

vector<int> g[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int n, k; cin >> n >> k;
	sz = n;
	iota(dsu, dsu+n+1, 0);

	for(int i=1; i<=k; ++i) cin >> rad[i];

	for(int i=1; i<=n; ++i) {
		cin >> ar[i].x >> ar[i].y >> ar[i].lvl;
		g[ar[i].lvl].pb(i);
	}

	using T = tuple<ll, ll, ll>;
	vector<T> edge;
	for(int i=k; i>=2; --i) {
		for(auto a : g[i]) {
			for(auto b : g[i-1]) {
				ll c = cost(ar[a], ar[b]);
				double d = sqrt(c);

				if(d > rad[i]) continue ;
				edge.pb(c, a, b);
			}
		}
	}


	ll res = 0;
	sort(edge.begin(), edge.end());
	for(auto [w, u, v] : edge) {
		if(par(u) == par(v)) continue ;
		res += w;
		un(u, v);
	}

	if(sz != 1) {
		cout << "Error\n";
		return 0;
	}

	cout << res << '\n';
	return 0;
}
