#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  ll a = 0, b = 1, r = 1;
  for(int i=2; i<=n; ++i) {
    ll c = a + b;
    a = b, b = c, r += b;
  }
  cout << r;
  return 0;
}