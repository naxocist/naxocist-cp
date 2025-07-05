#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 2e3 + 1;
int ar[N][N];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int m, n, r; cin >> m >> n >> r;

  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      char c; cin >> c;
      int x = c-'0';
      if(c == 'L') x = -1;
      ar[i][j] = x;
    }
  }

  ll s = 0, res = 0;
  for(int i=0; i<n; ++i) {
    for(int j=i&1?m-1:0; j>=0 and j<m; j+=i&1?-1:1) {

      int lv = 0;
      for(int a=i-1; a<=i+1; ++a){
        for(int b=j-1; b<=j+1; ++b) {
          if(a < 0 or b < 0 or a >= n or b >= m) continue ;
          lv += ar[a][b] == -1;
        }
      }

      if(ar[i][j] == -1) {
        if(lv >= 4) {
          res += s*r;
        }else {
          res += s/r;
        }
        s = 0;
        continue ;
      }

      s += ar[i][j];
    }
  }

  cout << res;
  return 0;
}