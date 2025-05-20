#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define pb emplace_back

const int N = 3e5 + 3;
vector<int> g[N], grev[N], adj[N], rev[N];
bitset<N> vis;
stack<int> st;
int cnt;
int mp[N];
int in[N];

void dfs(int u) {
  if(vis[u]) return ;
  vis[u] = 1;
  for(int v : g[u]) dfs(v);
  for(int v : adj[u]) dfs(v);
  st.push(u);
}

void dfs2(int u) {
  if(vis[u]) return ;
  vis[u] = 1;
  mp[u] = cnt;
  for(int v : grev[u]) dfs2(v);
  for(int v : rev[u]) dfs2(v);
}

void runcase() {
  int n, z, t, d; cin >> n >> z >> t >> d;

  vector<pii> edge, edge2;
  while(z--) {
  	int u, v; cin >> u >> v; g[u].pb(v), grev[v].pb(u), edge.pb(u, v);
  }

  for(int i=0; i<t; ++i) {
  	int u, v; cin >> u >> v; edge2.pb(u, v);
  }

  int l = -1, r = t + 1;
  while(l + 1 < r) {
  	int m = l + (r-l)/2;
  	for(int i=0; i<n; ++i) adj[i].clear(), rev[i].clear();
  	for(int i=0; i<m; ++i) {
  		auto [u, v] = edge2[i];
  		adj[u].pb(v);
  		rev[v].pb(u);
  	}

  	vis.reset();
  	for(int i=0; i<n; ++i) dfs(i);

  	cnt = 0;
  	// mp.clear();
  	vis.reset();
  	while(st.size()) {
  		int u = st.top(); st.pop();
  		if(vis[u]) continue ;
  		cnt ++;
  		dfs2(u);
  	}

  	for(int i=1; i<=cnt; ++i) in[i] = 0;
  	for(auto [u, v] : edge) if(mp[u] != mp[v]) in[mp[v]] ++;
  	for(int i=0; i<m; ++i) {
  		auto [u, v] = edge2[i];
  		if(mp[u] != mp[v]) in[mp[v]] ++;
  	}

  	int c = 0;
  	for(int i=1; i<=cnt; ++i) if(in[i] == 0) c ++;
  	if(c - 1 <= d) r = m; 
  	else l = m;
  }

  if(r == t + 1) r = -1;
  cout << r;
  return ;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC; 
  while(TC--) runcase();
  return 0;
}
