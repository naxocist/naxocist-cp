#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string a, b;
  map<string, vector<string>> mp;
  vector<string> ord;
  while(cin >> a >> b) {
    if(mp.find(b) == mp.end()) ord.pb(b);
    mp[b].pb(a);
  }

  for(auto x : ord) {
    cout << x << ": ";
    for(auto t : mp[x]) cout << t << ' ';
    cout << ln;
  }

  return 0;
}

