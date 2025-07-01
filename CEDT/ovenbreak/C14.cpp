#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int x, y, z; cin >> x >> y >> z;

  while(y > 0) {
    while(x%2 > y%4) {
      x += 2, y = x/2;
      if(z < y+2) z += 3;
    }
    y -= 2;
  }

  y = z + 3;
  z = 5 + x;
  cout << x << ' ' << y << ' ' << z;
  return 0;
}