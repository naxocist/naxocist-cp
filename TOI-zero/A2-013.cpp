#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  char c; int x; cin >> c >> x;
  char z; int a, b; cin >> z >> a >> b;

  int res = 0;
  if(c == 'H') res += 5*x;
  else if(c == 'O') res += 3*x;
  else if(c == 'J') res += 2*x;

  if(z == 'R') {
    if(a == 1) res += 12*b;
    if(a == 2) res += 18*b;
    if(a == 3) res += 25*b;
  } else if(z == 'T') {
    if(a == 1) res += 15*b;
    if(a == 2) res += 20*b;
    if(a == 3) res += 30*b;
  } else if(z == 'M') {
    if(a == 1) res += 10*b;
    if(a == 2) res += 15*b;
    if(a == 3) res += 20*b;
  }

  cout << res;
  return 0;
}
