#include <bits/stdc++.h>
using namespace std;


#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, u, v; cin >> n >> u >> v;

  vector<double> q(n); for(auto &x : q) cin >> x;

  vector<double> a, b;

  for(int i=0; i<n; i+=u) a.emplace_back(q[i]);
  for(int j=n-1; j>=0; j-=v) b.emplace_back(q[j]);

  double res = 0;
  vector<double> tt;
  int d = min(a.size(), b.size());
  for(int i=0; i<d; ++i) {
    res += a[i]*b[i];
  }

  res /= d;

  a.resize(d);
  b.resize(d);
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  double ma, mb;
  if(d&1) ma = a[d/2];
  else ma = (a[d/2-1] + a[d/2])/2;

  if(d&1) mb = b[d/2];
  else mb = (b[d/2-1] + b[d/2])/2;

  cout << fixed << setprecision(2) << res << ' ' << ma << ' ' << mb;
  return 0;
}