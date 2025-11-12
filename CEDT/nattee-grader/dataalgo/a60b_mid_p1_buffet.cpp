#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int f, w, n; cin >> f >> w >> n;
  vector<int> v(f); for(auto &x : v) cin >> x;
  sort(v.begin(), v.end());

  int far = -1, res = 0;
  for(auto &x : v) {
    if(far < x) {
      far = x + 2*w;
      res ++;
    }
  }
  cout << res;
  return 0;
}
