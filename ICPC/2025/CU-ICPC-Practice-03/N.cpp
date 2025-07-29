#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

ll dp[19][2][20];
string s;
ll dfs(int i, bool tight, int cnt) {
  if(i == s.size()) return cnt <= 3;

  if(dp[i][tight][cnt] != -1) return dp[i][tight][cnt];

  int lim = tight ? s[i] - '0' : 9;
  ll r = 0;
  for(int k=0; k<=lim; ++k) {
    bool t = tight and k == lim;
    int c = cnt + (k>0);
    r += dfs(i+1,t,c);
  }

  return dp[i][tight][cnt] = r;
}

ll f(ll x) {
  s = to_string(x);
  memset(dp, -1, sizeof dp);
  return dfs(0, 1, 0);
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
