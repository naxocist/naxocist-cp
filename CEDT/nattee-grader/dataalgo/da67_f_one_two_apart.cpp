#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 3;
const int mod = 1e8 + 7;
int dp[N][3][3];

int main() {
  int n; cin >> n;

  for(int x=0; x<3; ++x) {
    dp[1][x][0] = 1;
  }

  for(int i=2; i<=n; ++i) {
    for(int x=0; x<3; ++x) {
      for(int y=0; y<3; ++y) {
        for(int z=0; z<3; ++z) {

          if(x == 1 && (y == 2 || z == 2)) continue ;
          if(x == 2 && (y == 1 || z == 1)) continue ;
          dp[i][x][y] += dp[i-1][y][z];
          dp[i][x][y] %= mod;
        }
      }
    }
  }

  int res = 0;
  for(int x=0; x<3; ++x) {
    for(int y=0; y<3; ++y) {
      res += dp[n][x][y]; res %= mod;
    }
  }
  cout << res;
  return 0;
}
