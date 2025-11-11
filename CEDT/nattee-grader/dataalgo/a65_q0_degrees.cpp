#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 3;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;

  vector<int> deg(n);
  int mxd = 0;
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      int x; cin >> x; deg[i] += x;
    }
    mxd = max(mxd, deg[i]);
  }

  vector<int> res(mxd + 1);
  for(auto &x : deg) res[x] ++;
  for(auto &x : res) cout << x << ' ';

  return 0;
}
