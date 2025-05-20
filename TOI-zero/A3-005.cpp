#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int n, m, l, r;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cin >> n >> m; vector<int> v(n + 1);
  while(m--) cin >> l >> r, l--, r--, v[l]++, v[r+1]--;

  for(int i=1; i<n; ++i) v[i] += v[i-1];

  cout << *max_element(all(v));
  return 0;
}
