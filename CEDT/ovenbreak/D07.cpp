#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> x(n), h(n);
  for(auto &a : x) cin >> a;
  for(auto &a : h) cin >> a;

  for(int i=0; i<n; ++i) {
    ll res = 0;
    for(int j=0; j<=i; ++j) res += x[i-j]*h[j];
    cout << res << ' ';
  }

  for(int i=1; i<n; ++i) {
    ll res = 0;
    for(int j=0; j<n-i; ++j) res += x[n-1-j]*h[i+j];
    cout << res << ' ';
  }
  return 0;
}