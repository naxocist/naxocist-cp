#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int x, y, z; cin >> x >> y >> z;
  if(z == 1) cout << x + y;
  else if(z == 2) cout << x - y;
  else if(z == 3) cout << x * y;
  else if(y == 0) cout << "cannot divide by zero";
  else if(z == 4) cout << x/y;
  else cout << x%y;

  return 0;
}