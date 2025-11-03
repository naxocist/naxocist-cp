#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;

  map<string, vector<string>> mp;
  vector<string> v;
  while(n --) {
    string s; cin >> s;
    v.pb(s);
    string x;
    while(1) {
      cin >> x;
      if(x == "*") break ;
      mp[s].pb(x);
    }
  }

  string t; cin >> t;
  vector<string> res;
  for(auto y : v) {
    if(y == t) continue ;
    bool ok = 0;
    for(string x : mp[y]) {
      if(find(all(mp[t]), x) != mp[t].end()) ok = 1;
    }

    if(ok) res.pb(y);
  }

  if(res.size()) for(auto x : res) cout << ">> " << x << ln;
  else cout << ">> Not Found";
  return 0;
}

