#include <bits/stdc++.h>
using namespace std;

int main() {
  double s, u, a; cin >> s >> u >> a;
  double r = sqrt(u*u + 2*a*s);
  cout << fixed << setprecision(2) << r;
  return 0;
}
