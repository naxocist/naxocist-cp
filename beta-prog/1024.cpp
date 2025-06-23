#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int s = 0;
  int n; cin >> n; vector<int> v(n); for(auto &x : v) cin >> x, s += x;

  int t = 1e9, B, C;
  int a = 0;
  for(int i=0; i<n-2; ++i) {
    a += v[i];
    int b = 0;
    for(int j=i+1; j<n-1; ++j) {
      b += v[j];
      int c = s - a - b;
      int mx = max({a, b, c}), mn = min({a, b, c});
      if(mx - mn < t) {
        t = mx - mn;
        B = i + 1, C = j + 1;
      }
    }
  }

  cout << B+1 << ' ' << C+1;
  return 0;
}
