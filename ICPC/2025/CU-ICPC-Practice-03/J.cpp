#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

vector<int> adj[26];
int col[26];

stack<char> st;

bool dfs(int u) {
  if(col[u] == 1) {
    return 1;
  }

  if(col[u] == 2) return 0; 

  col[u] = 1;

  for(int v : adj[u]) {
    if(col[v] == 2) continue ;
    if(dfs(v)) return 1;
  }

  col[u] = 2;
  st.emplace('a'+u);
  return 0;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  string p;

  for(int i=0; i<n; ++i) {
    string s; cin >> s;
    if(i) {
      for(int i=0; i<min(s.size(), p.size()); ++i) {
        if(s[i] != p[i]) {
          int px = p[i]-'a', sx = s[i]-'a';
          adj[px].pb(sx);
          goto g;
        }
      }

      if(p.size() > s.size()) cout << "Impossible", exit(0);
    }
    g:;
    p = s;
  }


  for(int i=0; i<26; ++i) {
    if(dfs(i)) cout << "Impossible", exit(0);
  }
  while(st.size()) {
    cout << st.top(); st.pop();
  }
  return 0;
}
