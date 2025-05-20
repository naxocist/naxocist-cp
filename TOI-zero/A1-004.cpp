#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int a, b, c; cin >> a >> b >> c;
  if(a < 5 or b < 20 or c < 25) cout << "fail";
  else cout << "pass";
  return 0;
}
