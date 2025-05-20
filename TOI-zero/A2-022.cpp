#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int l, n; cin >> l >> n;
  vector<int> v(l + 1);
  while(n--) {
  	int a, b; cin >> a >> b; v[a] ++, v[b] --;
  }

  for(int i=1; i<=l; ++i) v[i] += v[i-1];

  cout << *max_element(all(v));
  return 0;
}
