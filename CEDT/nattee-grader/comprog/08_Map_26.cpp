#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string s;

  map<string, vector<string>> mp;
  set<string> res;
  while(getline(cin, s)) {
    int id = s.find(' ');
    string a = s.substr(0, id), b = s.substr(id + 1);
    if(id == -1) {
      res.insert(a);
      for(auto s : mp[a]) {
        res.insert(s);
        for(auto z : mp[s]) {
          res.insert(z);
        }
      }
      break ;
    }
    mp[a].pb(b);
    mp[b].pb(a);
  }

  for(auto x : res) cout << x << ln;


  return 0;
}

