#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, k; cin >> n >> k;
  vector<int> a(n), b(n), c(n), d(n);
  for(auto &x : a) cin >> x;
  for(auto &x : b) cin >> x;
  for(auto &x : c) cin >> x;
  for(auto &x : d) cin >> x;
   sort(all(a)); sort(all(b)); sort(all(c)); sort(all(d));

   int res = INT_MAX;
   for(int i=0; i<=k; ++i) {
     if(i > n or k-i > n) continue ;
     int mx = 0;
     for(int j=0; j<i; ++j) mx = max(mx, a[j]+c[i-j-1]);
     for(int j=0; j<k-i; ++j) mx = max(mx, b[j]+d[k-i-j-1]);
     res = min(res, mx);
   }
   cout << res;
  return 0;
}
