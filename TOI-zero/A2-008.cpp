#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> v(n); for(auto &x : v) cin >> x >> x;

  int res = 0
  for(int i=n-2; i>=0; --i) {
  	if(v[i] < v[i+1]) res ++, v[i] = v[i+1];
  }

	cout << res;
  return 0;
}
