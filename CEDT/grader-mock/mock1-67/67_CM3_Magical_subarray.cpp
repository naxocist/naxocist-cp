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
  vector<int> v(n); for(auto &x : v) cin >> x;

  int res = 0;
  for(int i=0; i<n; ++i) {
    for(int j=i; j<n; ++j) {

      int len = j-i+1;
      vector<int> cnt(len + 1);
      bool ok = 1;
      for(int k=i; k<=j; ++k) {
        int x = v[k];
        if(x < 1 or x > len or ++ cnt[x] > 1) ok = 0;
      }

      res += ok;
    }
  }

  cout << res;
  return 0;
}

