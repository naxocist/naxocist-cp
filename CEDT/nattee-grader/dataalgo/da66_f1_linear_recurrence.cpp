#include <bits/stdc++.h>
using namespace std;
const int mod = 32717;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int k, n; cin >> k >> n;
  vector<int> v(n + 1), c(k);
  for(auto &x : c) cin >> x;
  for(int i=0; i<=n; ++i) {
    if(i < k) {
      cin >> v[i];
      continue ;
    }
    for(int j=0; j<k; ++j) {
      v[i] += v[i-j-1]*c[j];
      v[i] %= mod;
    }
  }
  cout << v[n];
  return 0;
}
