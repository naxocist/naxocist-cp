#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int a, b, c, d, e; cin >> a >> b >> c >> d >> e;

  if(a > b) swap(a, b);
  if(c > d) swap(c, d);
  if(a > c) swap(b, d), c = a;
  a = e;

  if(a > b) swap(a, b);
  if(c > a) swap(b, d), a = c;

  if(a > d) cout << d;
  else cout << a;
  return 0;
}
