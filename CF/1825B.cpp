#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int q; cin >> q;
  while(q--) {
    int n, m; cin >> n >> m;
    vector<int> v(n*m); for(auto &x : v) cin >> x;
    sort(v.rbegin(), v.rend());

    int d1 = v[0]-v[n*m-1], d2 = max(v[0]-v[n*m-2], v[1]-v[n*m-1]);
    int res = d1*(n-1)*(m-1);
    res += d1*(max(n, m)-1);
    res += d2*(min(n, m)-1);
    cout << res << '\n';
  }
  return 0;
}
