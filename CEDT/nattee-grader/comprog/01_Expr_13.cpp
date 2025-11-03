#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  double a, b, c; cin >> a >> b >> c;

  double x1 = (-b - sqrt(b*b - 4*a*c))/(2*a);
  double x2 = (-b + sqrt(b*b - 4*a*c))/(2*a);

  x1 = round(x1*1e3)/1e3;
  x2 = round(x2*1e3)/1e3;

  cout << x1 << ' ' << x2;
  return 0;
}
