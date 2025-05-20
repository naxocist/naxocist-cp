#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int a, b, c; cin >> a >> b >> c;
  if(c > b and b > a) cout << "increasing";
  else if(a > b and b > c) cout << "decreasing";
  else cout << "neither";
  return 0;
}
