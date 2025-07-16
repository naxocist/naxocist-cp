#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const ll N = 2e5 + 3, M = 503;
bool no[N];
int ar[M][M];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  vector<int> p;
  for(ll i=2; i<N; ++i) {
    if(no[i]) continue ;
    p.pb(i);
    for(ll j=i*i; j<N; j+=i) no[j] = 1;
  }

  int n, m; cin >> n >> m;

  int res = INT_MAX;
  for(int i=0; i<n; ++i) {
    int s = 0;
    for(int j=0; j<m; ++j) {
      int x; cin >> x;
      auto t = lower_bound(all(p), x);
      if(*t < x) ++t;
      ar[i][j] = *t-x;
      s += ar[i][j];
      // cout << ar[i][j] << ' ';
    }
    // cout << ln;
    res = min(res, s);
  }


  for(int i=0; i<m; ++i) {
    int s = 0;
    for(int j=0; j<n; ++j) {
      s += ar[j][i];
    }
    res = min(res, s);
  }


  cout << res;
  return 0;
}

