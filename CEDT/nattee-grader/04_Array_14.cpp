#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  double ar[n][m];
  for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin >> ar[i][j];


  for(int i=1; i<n-1; ++i) {
    for(int j=1; j<m-1; ++j) {

      double res = 0;
      for(int h=i-1; h<=i+1; ++h) {
        for(int k=j-1; k<=j+1; ++k) res += ar[h][k];
      }
      res /= 9;
      res = round(res*100)/100;
      cout << res << ' ';
    }
    cout << ln;
  }
  return 0;
}

