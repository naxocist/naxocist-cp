#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int f(double x, double rate) {
  return ceil(x*rate);
}
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  double x; cin >> x;

  if(x > 4e6) cout << f(x, 0.3);
  else if(x > 2e6) cout << f(x, 0.25);
  else if(x > 1e6) cout << f(x, 0.20);
  else if(x > 5e5) cout << f(x, 0.15);
  else if(x > 3e5) cout << f(x, 0.10);
  else if(x > 150000) cout << f(x, 0.05);
  else cout << 0;
  return 0;
}