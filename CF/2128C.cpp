#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> v(n); for(auto &x : v) cin >> x;
    int mn = INT_MAX;
    for(int i=0; i<n; ++i) {
      if(i and v[i] >= 2*mn) {
        cout << "NO\n";
        goto g;
      }
      mn = min(mn, v[i]);
    }

    cout << "YES\n";
    g:;
  }
  return 0;
}
