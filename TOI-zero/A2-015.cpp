#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int a, b, c, d; cin >> a >> b >> c >> d;
  int r = 2*(a+b)*c; cout << r << ln << r*d;
  return 0;
}
