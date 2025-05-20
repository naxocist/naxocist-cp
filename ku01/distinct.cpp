#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n; vector<int> v(n); for(auto &x : v) cin >> x;

  set<int> st;
  for(int i=0; i<n; ++i) {
  	for(int j=i, s=0; j<n; ++j) s += v[j], st.insert(s);
  }

	cout << st.size();
  return 0;
}
