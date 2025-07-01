#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  int k = n;

  int s = 0;
  double ps = 0;
  while(k--) {
    int x; double p; cin >> x >> p;
    s += x, ps += x*p;
  }

  if(s >= 2*n) {
    ps *= 0.97;
    if(s > 14 and ps > 25) ps -= 10;
  }else if(s <= 20 and ps < 500) {
    ps += 600;
  }else {
    ps -= n*0.35;
  }
  ps = floor(ps); cout << ps;

  return 0;
}