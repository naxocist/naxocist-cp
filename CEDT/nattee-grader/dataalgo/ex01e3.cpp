#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q; cin >> n >> q;
  vector<int> v(n); for(auto &x : v) cin >> x;

  while(q--) {
    int x; cin >> x;
    auto t = upper_bound(v.begin(), v.end(), x);
    if(t == v.begin()) cout << -1;
    else cout << *prev(t);
    cout << '\n';
  }
  return 0;
}
