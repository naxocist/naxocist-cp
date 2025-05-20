#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string a, b; cin >> a >> b;
  cout << "Hello " << a << ' ' << b << ln;
  cout << a.substr(0, 2) << b.substr(0, 2);
  return 0;
}
