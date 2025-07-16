#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 2e5 + 3;
ll ar[N], dp[N], idx[N], qs[N];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, k; cin >> n >> k;

  for(int i=1; i<=n; ++i) cin >> ar[i], qs[i]=qs[i-1]+ar[i];
  for(int i=n-k+1; i>=1; --i) {
    ll r = qs[i+k-1]-qs[i-1];
    dp[i] = dp[i+1], idx[i] = idx[i+1];
    if(r >= dp[i+1]) {
      dp[i] = r;
      idx[i] = i;
    }
  }

  ll res = 0, mx = 0;
  int a,b;
  for(int i=k; i<=n; ++i) {
    mx = max(mx, qs[i]-qs[i-k]);
    ll r = mx+dp[i+1];
    if(r > res) {
      res = r;
      a = i-k+1, b = idx[i+1];
    }
  }
  cout << a << ' ' << b;
  return 0;
}