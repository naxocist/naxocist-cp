#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 1e5 + 3;
int req[N];
vector<pair<int, int>> adj[N];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m; cin >> n >> m;

  for(int i=0; i<m; ++i){
  	int k; cin >> k;
  	vector<int> vec(k); for(auto &u : vec) cin >> u, u--;

  	int v; cin >> v; v--;
  	req[i] = vec.size();
  	for(auto u : vec) adj[u].pb(v, i);
  }

	int res = 0;
	queue<int> q;
	q.emplace(0);
	vector<bool> vis(n);
	while(q.size()) {
		int u = q.front(); q.pop();
		if(vis[u]) continue ;
		vis[u] = 1;
		res ++;
		for(auto [v, i] : adj[u]) {
			if(--req[i] == 0) q.emplace(v);
		}
	}

	cout << res;
  return 0;
}
