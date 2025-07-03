#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
vector<int> adj[N];
bool vis[N];

void dfs(int u) {
	if(vis[u]) return ;
	vis[u] = 1;
	for(auto v : adj[u]) {
		dfs(v);
	}
}
int main() {
	int n, m; cin >> n >> m;
	while(m--) {
		int u, v; cin >> u >> v; adj[u].push_back(v), adj[v].push_back(u);
	}

	int cnt =0;
	for(int i=0; i<n; ++i) {
		if(vis[i]) continue ;
		cnt ++;
		dfs(i);
	}
	cout << cnt;
	return 0;
}