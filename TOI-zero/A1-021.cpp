#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int x; cin >> x;
  cout << (x < 1582 or x % 400 == 0 or (x % 4 == 0 and x % 100) ? "yes" : "no");
  return 0;
}
