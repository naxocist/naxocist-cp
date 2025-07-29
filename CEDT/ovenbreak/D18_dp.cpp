#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 3;
int l[N], s[N], h[N];


struct state {
  int sad = -1, happy = -1;
};

int main() {
  int lim, n; cin >> lim >> n;
  vector<state> dp(lim + 1);
  dp[0].sad = 0, dp[0].happy = 0;

  for(int i=0; i<n; ++i) {
    int x, c, v; cin >> x >> c >> v;
    l[i] = x;
    if(c == 1) s[i] = v;
    else h[i] = v;

    for(int j=lim; j>=0; --j) {
      int nl = j + l[i];
      int ns = dp[j].sad + s[i];
      int nh = dp[j].happy + h[i];
      if(nl > lim or dp[j].sad == -1) continue ;

      if(min(dp[nl].sad,dp[nl].happy) < min(ns, nh)) {
        dp[nl].sad = ns, dp[nl].happy = nh;
      }
    }
  }


  int res = 0;
  for(int i=0; i<=lim; ++i) {
    res = max(res, min(dp[i].sad, dp[i].happy));
  }
  cout << res;
  return 0;
}
