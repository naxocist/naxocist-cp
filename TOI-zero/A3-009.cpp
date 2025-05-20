#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int n, k, x; 
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cin >> n >> k;
  vector<int> v(k);
  while(n--) cin >> x, v[x-1] ++;

  int res = 0, mn = *min_element(all(v));
  for(auto x : v) res += x - mn;

  cout << res;
  return 0;
}
