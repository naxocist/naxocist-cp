#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, d, t, z; cin >> n >> d >> t >> z;

  vector<pair<int, int>> v;

  map<int, vector<int>> src;
  for(int i=0; i<d; ++i) {
    int tired, item; cin >> tired >> item;
    src[item].pb(tired);
  }
  for(auto &[x, y] : src) sort(y.begin(), y.end());

  vector<int> went(src.size());
  int res = 0;
  for(int i=0; i<n; ++i) {
    int m; cin >> m;
    bool ok = true;
    while(m --) {
      int x; cin >> x;
      if(went[x] == src[x].size()) {
        ok = false;
        break ;
      }
      auto tired = src[x][went[x] ++];
      t -= tired;
      if(t < 0) {
        ok = false;
        break ;
      }
    }
    if(ok) res ++;
    else break ;
  }
  cout << res;
  return 0;
}
