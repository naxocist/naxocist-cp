#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

using pi = pair<int, int>;
const int N = 1e5 + 3;

map<int, vector<pi>> mp;
set<pi> vis;

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int r, c, a, b; cin >> r >> c >> a >> b;
  int n; cin >> n;

  for(int i=0; i<n; ++i) {
    int rr, l, r; cin >> rr >> l >> r;
    mp[rr].pb(l,r);
  }

  using T = tuple<int, int, int>;
  queue<T> q;
  q.emplace(r,c,0);
  while(q.size()) {
    auto [r,c,d] = q.front(); q.pop();
    if(r == a and c == b) cout << d, exit(0);

    if(vis.find(pi(r,c)) != vis.end()) continue ;
    vis.emplace(r,c);

    int tr[] = {-1,-1,-1,0,0,1,1,1};
    int tc[] = {-1,0,1,-1,1,-1,0,1};

    for(int i=0; i<8; ++i) {
      int nr = r+tr[i], nc = c+tc[i];
      for(auto [l,r] : mp[nr]) {
        if(l <= nc and nc <= r) q.emplace(nr,nc,d+1);
      }
    }
  }


  cout << -1;
  return 0;
}
