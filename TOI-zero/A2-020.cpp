#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n; vector<int> v(n); for(auto &x : v) cin >> x, x--;

  vector<bool> vis(n);
  int mx = 0;
  for(int i=0; i<n; ++i) {
    if(vis[i]) continue ;
    int u = i, cnt = 0;
    do {
    	u = v[u]; cnt ++; vis[u] = 1;
    } while(u != i);
    mx = max(mx, cnt);
  }

  cout << mx;
  return 0;
}
