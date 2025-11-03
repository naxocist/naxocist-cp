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
  map<string, double> mp;
  mp["THB"] = 1;
  while(n --) {
    string a; double b; cin >> a >> b; mp[a] = b;
  }

  int x; string y; cin >> x >> y;
  bool first = 1;
  while(1) {
    if(!first) cout << " -> ";
    cout << x << ' ' << y;

    string nx;
    if(!(cin >> nx)) break ;

    x = mp[y]/mp[nx] * x;
    y = nx;
    first = 0;
  }
  return 0;
}

