#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int q; cin >> q;

  int mn = INT_MAX;
  while(q--) {
  	int x; cin >> x; mn = min(mn, x);
  }
  cout << mn;
  return 0;
}
