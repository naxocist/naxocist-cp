#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define pb emplace_back

const int N = 1e5 + 3;
vector<int> g[N], adj[N], rev[N];
bitset<N> vis;
stack<int> st;
int in[N];

void runcase() {
	int n, z, t, d; cin >> n >> z >> t >> d;

	vector<pii> edge, edge2;
	while(z--) {
		int u, v; cin >> u >> v; g[u].pb(v), edge.pb(u, v);
	}

	for(int i=0; i<t; ++i) {
		int u, v; cin >> u >> v; edge2.pb(u, v);
	}

	for(int m=0; m<=t; ++m){
		for(int i=0; i<n; ++i) adj[i].clear();
		for(int i=0; i<m; ++i) {
			auto [u, v] = edge2[i];
			adj[u].pb(v);
		}

		for(int i=0; i<n; ++i) in[i] = 0;
		for(auto [u, v] : edge) in[v] ++;
		for(int i=0; i<m; ++i) {
			auto [u, v] = edge2[i];
			in[v] ++;
		}

		int c = 0;
		for(int i=0; i<n; ++i) if(in[i] == 0) c ++;
		if(c - 1 <= d) {
			cout << m;
			return ;
		}
	}

	cout << -1;
	return ;
}

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int TC = 1;
	// cin >> TC; 
	while(TC--) runcase();
	return 0;
}
