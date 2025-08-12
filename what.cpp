#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;

  vector<int> v(n);
  for(int i=0; i<n; ++i) {
    int x; cin >> x;
    v[i] = x;
  }

  sort(all(v));

  for(auto x : v) {
    cout << x * x << ln;
  }
  return 0;
}

