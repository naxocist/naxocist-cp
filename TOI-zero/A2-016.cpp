#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  char a, x; string b, y; cin >> a >> b >> x >> y;

  if(a == x) {
    if(b == y) cout << 1000000;
    else if(b.substr(2, 3) == y.substr(2, 3)) cout << 2000;
    else if(b.substr(3, 2) == y.substr(3, 2)) cout << 1000;
    else cout << 20;
  }else {
    if(b == y) cout << 100000;
    else if(b.substr(2, 3) == y.substr(2, 3)) cout << 200;
    else if(b.substr(3, 2) == y.substr(3, 2)) cout << 100;
    else cout << 0;
  }
  return 0;
}
