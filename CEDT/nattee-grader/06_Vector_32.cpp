#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back


bool cmp(vector<int> a, vector<int> b) {
  int sa = 0, sb = 0; for(auto x : a) sa += x; for(auto x : b) sb += x;
  if(sa != sb) return sa > sb;

  if(a.size() != b.size()) return a.size() < b.size();

  return a < b;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string op; cin >> op;

  vector<vector<int>> vv;
  int x;
  while(cin >> x) {
    bool ok = 0;

    int mn = INT_MAX, idx = -1;
    for(int i=0; i<(int)vv.size(); ++i) {
      vector<int> &v = vv[i];

      int s = 0;
      for(auto y : v) s += y;
      if(s + x > 100) continue ;
      
      if(op == "first") {
        v.pb(x); ok = 1; break ;
      }

      if(100-s-x < mn) {
        mn = 100-s-x;
        idx = i;
      }
      mn = min(mn, 100-s-x);
    }

    if(op == "best" and idx != -1) {
      vv[idx].pb(x); ok = 1;
    }

    if(!ok) vv.push_back({x});
  }

  for(auto &v : vv) sort(all(v));

  sort(all(vv), cmp);

  for(auto v : vv) {
    for(auto x : v) cout << x << ' '; cout << ln;
  }
  return 0;
}

