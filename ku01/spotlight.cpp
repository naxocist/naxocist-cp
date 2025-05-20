#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

using pi = pair<int, int>;

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  vector<pi> v;
  while(n--) {
    int a, b; cin >> a >> b;
    if(a < b) v.pb(a, b);
    else v.pb(a, 360), v.pb(0, b);
  }
  sort(all(v));

  vector<pi> merged;
  int cl = -1, cr = -1;
  for(auto [l, r] : v) {
    if(l <= cr) cr = max(r, cr); 
    else {
    	if(cl != -1) merged.pb(cl, cr);
    	cl = l, cr = r;
    }
  }

  merged.pb(cl, cr);

  int m = merged.size(), mx = 0;
  for(int i=1; i<merged.size()-1; ++i) {
    auto [a, b] = merged[i];
    mx = max(mx, b-a);
  }

  int frst = merged[0].second - merged[0].first;
  int lst = merged[m-1].second - merged[m-1].first;
  if(merged[0].first == 0 and merged[m-1].second == 360 and m > 1) mx = max(mx, frst + lst);
  else mx = max({mx, frst, lst});

  cout << mx;
  return 0;
}
