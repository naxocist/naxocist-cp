#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  char a, b, c; int x; cin >> a >> b >> c >> x;

  int res = 0;
  if(a == 'S') res += (b == 'R' ? 60 : 80);
  if(a == 'M') res += (b == 'R' ? 80 : 100);
  if(a == 'L') res += (b == 'R' ? 100 : 120);

  if(c == 'P') res += 15*x;
  if(c == 'E') res += 10*x;
  
  cout << res;
  return 0;
}
