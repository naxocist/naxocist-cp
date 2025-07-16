#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 2e3 + 1;
ll dp[N][N], mn[N][N], mx[N][N];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  vector<ll> v(n); for(auto &x : v) cin >> x;
  sort(all(v));

  for(int i=0; i<n; ++i) 
    for(int j=i; j<n; ++j) {
    mx[i][j] = max(v[j], j>i ? mx[i][j-1] : INT_MIN);
    mn[i][j] = min(v[j], j>i ? mn[i][j-1] : INT_MAX);
  }

  for(int sz=2; sz<=n; ++sz) {
    for(int l=0; l<n; ++l) {
      int r = l + sz - 1;
      if(r >= n) break ;
      dp[l][r] = mx[l][r] - mn[l][r] + min(dp[l+1][r], dp[l][r-1]);
    }
  }

  cout << dp[0][n-1];
  return 0;
}