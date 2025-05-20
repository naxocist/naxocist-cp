#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int l, n, a, b, c, x, y, z, t, p;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cin >> l >> n >> a >> b >> c;

  while(n--) {
    cin >> t >> p;
    if(t % a == 0) x += p;
    if(t % b == 0) y += p;
    if(t % c == 0) z += p;
  }

  int mx = max({x, y, z});
  if(x == mx) cout << "Rabbit " << x << ln;
  if(y == mx) cout << "Monkey " << y << ln;
  if(z == mx) cout << "Frog " << z;
  return 0;
}
