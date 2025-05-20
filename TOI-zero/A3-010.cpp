#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, k, t; cin >> n >> k >> t; t--;

  vector<bool> vis(n);
  int u = 0, c = 0;
  while(!vis[u]) {
    c ++;
    vis[u] = 1;
    if(u == t) break ;
    u = (u + k)%n;
  }

  cout << c;

  return 0;
}
