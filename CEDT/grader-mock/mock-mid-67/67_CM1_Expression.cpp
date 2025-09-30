#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  double x; cin >> x;
  double c = cos(x*M_PI/180), s = sin(x*M_PI/180);
  double a = sqrt(x*x + c*c);
  double b = s + c*c*c/(x*x + 1);

  a /= b;
  cout << fixed << setprecision(1) << a;
  return 0;
}

