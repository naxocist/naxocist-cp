#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string a, b; int x; cin >> a >> b >> x;

  if(a.size() > 5 and b.size() > 5) cout << a.substr(0, 2) + b.back() << x%10;
  else cout << a[0] << x << b.back();
  return 0;
}
