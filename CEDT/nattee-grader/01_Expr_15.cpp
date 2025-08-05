#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  double x; cin >> x;

  double y = pow(x, sqrt(log((x+1)*(x+1)))) / (10 - x);
  y = round(y*1e6)/1e6;
  cout << y;
  return 0;
}
