#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 123;
int a[N], b[N];
bool u[N], v[N];

const ll mod = 1e4 + 7;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, t, e; cin >> n >> t >> e;
  for(int i=0; i<n; ++i) cin >> a[i] >> b[i];

  ll tt = 0, ee = 1;
  bool aa = 1; int k = 0;
  for(int i=0; i<n; ++i) {
    int x = aa ? a[i] : b[i];
    if(aa) u[i] = 1;
    else v[i] = 1;
    if(x <= 0) continue ;
    tt += x; tt %= mod;
    if(++k == t) aa ^= 1, k = 0;
  }

  aa = 0, k = 0;
  for(int i=0; i<n; ++i) {
    int x = aa ? a[i] : b[i];
    if(aa) u[i] = 1;
    else v[i] = 1;
    if(x <= 0) continue ;
    ee *= x; ee %= mod;
    if(++k == e) aa ^= 1, k = 0;
  }


  int mx = 0, c = 0;
  for(int i=0; i<n; ++i) {
    if(!u[i]) mx = max(mx, ++c);
    else c = 0;
  }
  int res = mx;
  mx = 0, c = 0;
  for(int i=0; i<n; ++i) {
    if(!v[i]) mx = max(mx, ++c);
    else c = 0;
  }
  res = max(res, mx);
  cout << tt << ' ' << ee << ' ' << res;
  return 0;
}