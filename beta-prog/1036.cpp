#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 1e4 + 3;
int ar[N], bs[N];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, k; cin >> n >> k;

  for(int i=0; i<n; ++i) {
    cin >> ar[i];

    int b = 0;
    for(int j=0; j<k; ++j) {
      int x; cin >> x;
      b |= x<<j;
    }
    bs[i] = b;
  }

  vector<int> dp(1<<k, 2e9);
  dp[0] = 0;
  for(int s=1; s < (1<<k); ++s) {
    for(int i=0; i<n; ++i) {
      int b = bs[i], t = s;
      for(int j=0; j<k; ++j) if(t&(1<<j)) t^=b&(1<<j);
      dp[s] = min(dp[s], dp[t] + ar[i]);
    }
  }

  cout << dp[(1<<k)-1];
  return 0;
}
