#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> v(n + 2);
  for(int i=1; i<=n; ++i) cin >> v[i];

  int res = 0;
  for(int i=1; i<=n; ++i) res += v[i-1] < v[i] and v[i+1] < v[i];
  cout << res;
  return 0;
}
