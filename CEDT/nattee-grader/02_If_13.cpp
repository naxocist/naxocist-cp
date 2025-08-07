#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  double a, b, c, d; cin >> a >> b >> c >> d;

  if(a > b) swap(a, b);
  if(b > c) swap(b, c);
  if(c > d) swap(c, d);
  if(a > b) swap(a, b);
  if(b > c) swap(b, c);
  if(a > b) swap(a, b);


  double res = (b+c)/2;

  res = round(res*100.0)/100.0;
  cout << res;
  return 0;
}
