#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q; cin >> n >> q;
  vector<bool> can(2e6 + 1);
  vector<int> v(n); for(auto &x : v) cin >> x;

  for(int i=0; i<n; ++i) {
    int x = v[i];
    for(int j=i+1; j<n; ++j) {
      int y = v[j];
      if(x + y > 2e6) continue ;
      can[x + y] = true;
    }
  }

  while(q --) {
    int x; cin >> x;
    if(can[x]) cout << "YES";
    else cout << "NO";
    cout << '\n';
  }
  return 0;
}
