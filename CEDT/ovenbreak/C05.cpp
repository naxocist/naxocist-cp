#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  ll res = 0, f = 1;
  for(int i=1; i<=n; ++i) f *= i, res += f;
  cout << res;
  return 0;
}