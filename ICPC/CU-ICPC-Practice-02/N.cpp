#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)

struct line {
  ll m, c;
};

vector<line> cht;

void insert(ll m, ll c) {
  auto f = [&](line x, line y, line z) {
    return (double)(z.c-x.c)*(y.m-z.m) <= (double)(z.c-y.c)*(x.m-z.m);
  };

  while(cht.size() >= 2 and f(cht[cht.size()-1], cht[cht.size()-2], {m, c})) 
    cht.pop_back();

  while(cht.size() and cht.back().m == m and cht.back().c >= c) 
    cht.pop_back();

  cht.push_back({m, c});
}

int idx = 0;
ll get(ll x) {

  auto cal = [&](int i) {
    return cht[i].m*x + cht[i].c;
  };

  if(idx >= cht.size()) idx = cht.size() - 1;
  while(idx + 1 < cht.size() and cal(idx + 1) <= cal(idx)) idx ++;

  return cal(idx);
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  vector<ll> a(n), b(n);
  for(auto &x : a) cin >> x;
  for(auto &x : b) cin >> x;

  // vector<ll> dp(n);
  // for(int i=1; i<n; ++i) {
  //   dp[i] = LLONG_MAX;
  //   for(int j=0; j<i; ++j) {
  //     dp[i] = min(dp[i], a[i]*b[j] + dp[j]);
  //   }
  // }
  // cout << dp.back();

  for(int i=0; i<n; ++i) {
    ll dp = i ? get(a[i]) : 0;
    insert(b[i], dp);
    if(i == n-1) cout << dp;
  }
  return 0;
}