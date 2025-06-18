#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
using ll = long long;
const int N = 1e5 + 3;
int dsu[N], sz;

int par(int u) {
	return (dsu[u] == u ? u : dsu[u] = par(dsu[u]));
}

void un(int u, int v) {
	u = par(u), v = par(v);
	if(u == v) return ;
	dsu[u] = v;
	sz --;
}


int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, k; cin >> n >> m >> k;

	vector<tuple<int, int, ll>> edges;

	ll l = -1, r = 0;
	while(m--) {
		int u, v; ll w; cin >> u >> v >> w; u--, v--; edges.pb(u, v, w);
		r = max(r, w);
	}

	r ++;
	while(l + 1 < r) {
		ll md = l + (r-l)/2;
		iota(dsu, dsu+n, 0);
		sz = n;
		for(auto [u, v, w] : edges) if(md <= w) un(u, v);

		if(sz <= k) l = md;
		else r = md;
	}

	if(l == -1) cout << "DEADLY SIN";
	else cout << l;

	return 0;
}
