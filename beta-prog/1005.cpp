#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n; vector<int> v(n); for(auto &x : v) cin >> x;

  int mx = 0, l, r;
  for(int i=0; i<n; ++i) {
    for(int j=i, s=0; j<n; ++j) {
      s += v[j];
      if(s > mx) {
        l = i, r = j;
        mx = s;
      }
    }
  }

  if(mx == 0) cout << "Empty sequence", exit(0);

  for (int i=l; i<=r; ++i) cout << v[i] << ' '; cout << '\n';
  cout << mx;
  return 0;
}
