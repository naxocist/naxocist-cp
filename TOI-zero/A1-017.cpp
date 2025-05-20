#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int a, b, c, x, y, z; cin >> a >> b >> c >> x >> y >> z;
  
  if(a == x and b == y and c == z) cout << 0;
  else if(a < x or (a == x and b < y) or (a == x and b == y and c < z)) cout << 1; 
  else cout << 2;
  
  return 0;
}
