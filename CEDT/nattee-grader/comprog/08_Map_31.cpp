#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  map<string, int> mp;
  int n; cin >> n;
  while(n--) {
    string s; int x; cin >> s >> x; mp[s] = x;
  }
  int m; cin >> m;

  using T = tuple<double, string, vector<string>>;
  vector<T> v;
  while(m--) {
    string s, a, b, c, d; double x;
    cin >> s >> x >> a >> b >> c >> d;
    vector<string> t = {a, b, c, d};
    v.pb(x, s, t);
  }

  sort(v.rbegin(), v.rend());

  map<string, string> res;
  for(auto [x, s, t] : v) {
    string r;
    for(auto s : t) {
      if(mp[s] > 0) {
        r = s;
        mp[s] --;
        break ;
      }
    }
    res[s] = r;
  }

  for(auto [a, b] : res) cout << a << ' ' << b << ln;

  return 0;
}

