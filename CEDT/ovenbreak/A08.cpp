#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll f(ll x) {
  return 4 * (x * (x+1))/2;
}
int main() {
  string s; ll a, b; cin >> s >> a >> b;

  cout << s << " has " << f(b) - f(a-1) << " attackable tiles.";
  return 0;
}
