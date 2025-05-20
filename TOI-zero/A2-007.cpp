#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

using pi = pair<int, int>;
const int N = 3e2 + 3;
vector<pi> covered[N];
vector<int> cover[N];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m; cin >> n >> m;

  vector<pi> v(n); for(auto &[a, b] : v) cin >> a >> b;

  for(int i=0; i<n; ++i) {
    auto [x, y] = v[i];
  	for(int j=0; j<n; ++j) {
      auto [a, b] = v[j];
      if(x < a and b < y) covered[j].pb(y-x, i), cover[i].pb(j); 
  	}

    covered[i].pb(y-x, i); cover[i].pb(i);
  }

  for(int i=0; i<n; ++i) sort(all(covered[i]));

  vector<int> q(m); for(auto &x : q) cin >> x, x--;

  vector<bool> picked(n); 
  vector<int> use;
  int res = 0;
  for(auto x : q) {
    if(picked[x]) continue ;
    res ++;
    picked[x] = 1;
    int r = x;

    for(auto [sz, p] : covered[x]) {
      for(auto cv : cover[p]) {
        if(find(all(q), cv) != q.end() and !picked[cv]) {
          picked[cv] = 1;
          r = p;
        }
      }
    }

    use.pb(r);
  }
  cout << res << ln;
  for(auto u : use) cout << u + 1 << ' ';
  return 0;
}
