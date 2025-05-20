#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<int> par, rk;
int mx=0;

int find_set(int v) {
  if (v == par[v])
    return v;
  return par[v] = find_set(par[v]);
}

void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if(rk[a] < rk[b]) swap(a, b);
    par[b] = a;
    if(rk[a] == rk[b]) rk[a]++;
  }
}

int dfs(int node, int head, vector<vector<int>>& adj) {
    vector<int> v;
    for(auto nei : adj[node]) {
        if(head != nei) {
            v.push_back(dfs(nei, node, adj)+1);
        }
    }
    if(v.size() == 0) {
        return 0;
    }else if(v.size() == 1) {
        mx = max(mx, v[0]);
        return v[0];
    }else {
        sort(v.begin(), v.end(), greater<int>());
        mx = max(mx, v[0]+v[1]);
        return v[0];
    }
}

int32_t main() {
  int n, m, k;
  cin >> n >> m >> k;

  // maximum spanning tree
  vector<tuple<int, int, int>> edges;
  vector<vector<int>> adj(n+1);

  for(int i=0; i<m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    edges.emplace_back(w, a, b);
  }

  int cost = 0;
  par.resize(n+1);
  rk.resize(n+1);

  for(int i=1; i<=n; i++)  {
    par[i] = i;
    rk[i] = 0;
  }

  sort(edges.begin(), edges.end(), greater<tuple<int, int, int>>());

  for(auto edge : edges) {
    int w, a, b;
    tie(w, a, b) = edge;
    if(find_set(a) != find_set(b)) {
      cost += w;
      adj[a].push_back(b);
      adj[b].push_back(a);
      union_sets(a, b);
    }
  }

  int c=0;
  for(int i=1; i<=n; i++) {
    if(par[i] == i) c++;
  }

  if(c > 1) {
    cout << "AYGOMH";
    return 0;
  } 

  cout << cost << endl;

  if(k == 0) return 0;

  // find diameter
  dfs(1, 0, adj);
  cout << mx << endl;
}