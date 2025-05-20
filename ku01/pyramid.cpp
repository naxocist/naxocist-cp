#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int l, n; cin >> l >> n;
  int s = 0, i = 0;
  while(s < n) i++, s += i*i;

  int res = l-i;
  if(s > n) res ++;
  cout << res;
  return 0;
}
