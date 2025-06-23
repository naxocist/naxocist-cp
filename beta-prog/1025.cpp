#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;

  ll y = 1;
  while(n--) {
    ll x; cin >> x;
    y = x*y/__gcd(x, y);
  }

  cout << y;
  return 0;
}
