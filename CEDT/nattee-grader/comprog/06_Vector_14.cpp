#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  vector<int> v;
  int x;
  while(cin >> x) {
    v.pb(x);
  }
  sort(all(v));

  vector<int> res;
  int p = -1;
  for(auto x : v) {
    if(x != p) res.pb(x);
    p = x;
  }

  cout << res.size() << ln;
  for(int i=0; i<min(10, (int)res.size()); ++i) cout << res[i] << ' ';

  return 0;
}

