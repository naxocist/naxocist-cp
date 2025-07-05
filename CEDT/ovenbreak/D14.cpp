#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int q; cin >> q;
  while(q--) {
    int n = 5;
    vector<int> v(n); for(auto &x : v) cin >> x;

    int res = 0;
    for(int i=0; i<n; ++i) {
      for(int j=0; j<i; ++j) {
        res += v[i] < v[j];
      }
    }

    if(res <= 1) cout << "Yes";
    else cout << "No";
    cout << ln;
  }
  return 0;
}