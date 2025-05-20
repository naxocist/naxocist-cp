#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int a, b, c; cin >> a >> b >> c;
  if(a == b and b == c) cout << "all the same";
  else if(a != b and a != c and b != c) cout << "all different";
  else cout << "neither";

  return 0;
}
