#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int k, n; cin >> k >> n;

  int res = 0;
  for(int i=0; i<k; ++i) res += n/(1<<i);
  // for(int i=1; i<=n; ++i) {
  //   res += __builtin_popcount(i^(i-1));
  //   // for(int j=0; j<k; ++j) res += (i&(1<<j))^((i-1)&(1<<j)) ? 1 : 0;
  // }

  cout << res;
  return 0;
}
