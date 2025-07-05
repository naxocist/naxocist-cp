#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;

  int s = n + 1;
  int mx = 0;
  vector<int> v(n);
  for(auto &x : v) cin >> x, s += x, mx = max(mx, x);

  for(int i=mx; i>=1; --i) {
    if(i == 1) cout << "_";
    else cout << " ";
    for(auto x : v) {
      if(i > x) {
        int k = 2*x+1;
        while(k--) cout << " ";
        continue ;
      }

      int d = x - i;
      for(int j=0; j<2*x; ++j) {
        if(j == x-1-d) cout << "/";
        else if(j == x+d) cout << "\\";
        else cout << " ";
      }
      if(i == 1) cout << "_";
      else cout << " ";
    }
    cout << ln;
  }
  return 0;
}