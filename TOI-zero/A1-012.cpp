#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int x; char op; cin >> x >> op;
  int y = 0, t = x;
  for(int t=x; t; t/=10) y *= 10, y += t%10;

  if(op == '+') printf("%d + %d = %d", x, y, x + y);
  else printf("%d * %d = %d", x, y, x * y);
  return 0;
}
