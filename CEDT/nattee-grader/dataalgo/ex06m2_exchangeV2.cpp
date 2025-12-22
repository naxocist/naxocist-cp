#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back
const int N = 503;
double dp[N][N];

void solve() {
  int n; cin >> n;
  for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) cin >> dp[i][j];

  for(int k=0; k<n; ++k) for(int i=0; i<n; ++i) for(int j=0; j<n; ++j)
    dp[i][j] = max(dp[i][j], dp[i][k] * dp[k][j]);

  for(int i=0; i<n; ++i) {
    if(dp[i][i] > 1.0) {
      cout << "YES\n";
      return ;
    }
  }
  cout << "NO\n";
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int T; cin >> T;
  while(T --) solve();
  return 0;
}
