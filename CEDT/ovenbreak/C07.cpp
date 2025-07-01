#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

ll dp[19][2][11];
string s;
ll dfs(int i, bool tight, int fs) {
  if(i == s.size()) return fs != 10;
  if(i == s.size() - 1 and fs == 10) return 0;
  
  if(dp[i][tight][fs] != -1) return dp[i][tight][fs];

  int lim = tight ? s[i] - '0' : 9;
  int nlim = fs == 10 ? lim : min(lim, fs - 1);
  ll r = 0;
  for(int k=0; k<=nlim; ++k) {
    bool t = tight and k == lim;
    if(fs == 10) {
      if(k == 0) r += dfs(i+1, t, 10);
      else r += dfs(i+1, t, k);
    }else {
      if(k >= fs) break ;
      r += dfs(i+1, t, fs);
    }
  }

  return dp[i][tight][fs] = r;
}

ll f(ll x) {
  s = to_string(x);
  memset(dp, -1, sizeof dp);
  return dfs(0, 1, 10);
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int q; cin >> q;
  while(q--) {
    ll l, r; cin >> l >> r;
    cout << f(r) - f(l-1) << ln;
  }
  return 0;
}
