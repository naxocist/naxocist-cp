#include <bits/stdc++.h>
using namespace std;

const int mod = 1e6 + 3;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k; cin >> n >> k;
  vector<int> v(k); for(auto &x : v) cin >> x;

  vector<int> res(n + 1);
  res[0] = 1;
  for(int i=1; i<=n; ++i) {
    for(auto &x : v) {
      if(i - x < 0) continue ;
      res[i] += res[i - x], res[i] %= mod;
    }
  }
  cout << res[n];
  return 0;
}
