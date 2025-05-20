#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, res = 0; string a, b; cin >> n >> a >> b;
  for(int i=0; i<n; ++i) res += a[i] + b[i] - '0' - '0' != 9;
  if(res) cout << "NO " << res;
  else cout << "YES";
  return 0;
}
