#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back


int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m, x, y, q; cin >> n >> m >> x >> y >> q;

  int ar[n][m] = {};

  while(q--) {
    int i, j; cin >> i >> j;
    for(int h=max(0, i-2); h<=min(n-1, i+2); ++h) {
      for(int k=max(0, j-2); k<=min(m-1, j+2); ++k) {
        int layer = max(abs(i-h), abs(j-k));
        // int danger = 0;
        // if(layer == 0) danger = 100;
        // else if(layer == 1) danger = 60;
        // else danger = 20;
        // ar[h][k] = max(ar[h][k], danger);
        
        int val = 3 - layer;
        ar[h][k] = max(ar[h][k], val);
      }
    }
  }


  int res = 0;
  for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) res += (ar[i][j] == 0);

  cout << res << ln;
  // cout << ar[x][y] << '%';
  int t = ar[x][y];
  if(t == 0) cout << "0%";
  else if(t == 1) cout << "20%";
  else if(t == 2) cout << "60%";
  else cout << "100%";
  return 0;
}

