#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<int> v(m); for(auto &x : v) cin >> x;
  sort(v.begin(), v.end());
  int res = INT_MAX;
  for(int i=0; i+n-1<m; ++i) {
    int j = i+n-1;
    res = min(res, v[j]-v[i]);
  }
  cout << res;
}

