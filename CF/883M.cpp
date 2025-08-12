#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int x, y, a, b; cin >> x >> y >> a >> b;

  if(x == a or y == b) {
    int l = abs(x-a) + abs(y-b);
    cout << 2*(l+1) + 4;
    return 0;
  }

  if(a > x and b > y) {
    a ++, b ++;
  }else if(a > x and b < y) {
    a ++, b --; 
  } else if(a < x and b > y) {
    a --, b ++;
  }else {
    a --, b--;
  }

  cout << 2*(abs(x-a) + abs(y-b));
  return 0;
}
