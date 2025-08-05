#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> v(n); for(auto &x : v) cin >> x;
  sort(v.begin(), v.end());

  int s; cin >> s;
  for(int i=0; i<n; ++i) {
    int x = v[i];
    int d = s - x;

    int l = -1, r = n;
    while(l + 1 < r) {
      int m = l + (r-l)/2;
      if(v[m] >= d) r = m;
      else l = m;
    }

    if(r == n or v[r] != d) continue ;
    if(r == i) {
      if(r + 1 > n) continue ;
      if(v[r] == v[r + 1]) cout << r << ' ' << r+1, exit(0);
      continue ;
    }

    cout << i << ' ' << r, exit(0);
  }
  return 0;
}
