#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  double xe, ye, re, rp, xm, ym; cin >> xe >> ye >> re >> rp >> xm >> ym;


  double c = re - rp;
  double C = sqrt((xe-xm)*(xe-xm) + (ye-ym)*(ye-ym));
  c /= C;
  double a = c * (xm-xe);
  double b = c * (ym-ye);
  double x = xe + a, y = ye + b;
  cout << round(x) << ' ' << round(y);
  return 0;
}
