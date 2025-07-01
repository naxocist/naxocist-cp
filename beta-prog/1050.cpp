#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, p; cin >> n >> p;
  map<vector<int>, int> mp;
  for(int i=1; i<=n; ++i) {
    vector<int> v(p); for(auto &x : v) cin >> x;
    mp[v] = i;
  }

  vector<int> tar(p); for(auto &x : tar) cin >> x;

  if(mp.find(tar) != mp.end()) {
    cout << mp[tar]; return 0;
  }

  for(auto [v, i] : mp) {
    vector<int> w;
    for(int k=0; k<p; ++k) w.pb(tar[k]-v[k]);
    if(mp.find(w) == mp.end() or mp[w] == i) continue ;
    int j = mp[w];
    cout << min(i, j) << ' ' << max(i, j);
    return 0;
  }

  cout << "NO";
  return 0;
}