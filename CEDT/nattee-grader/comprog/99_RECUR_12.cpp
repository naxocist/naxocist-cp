#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  ll a, b, k; cin >> a >> b >> k;

  ll res = 1;
  while(b) {
    if(b & 1) res *= a, res %= k;
    a *= a, a %= k;
    b >>= 1;
  }
  
  cout << res;
  return 0;
}

