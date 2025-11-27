#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back
const int N = 161;
int dp[N][N][N];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int d, h, w; cin >> d >> h >> w;

  for(int i=0; i<h*d; ++i) {
    for(int c=1; c<=w; ++c){
      int x; cin >> x;
      int a = i/h, b = i%h; a++, b++;
      dp[a][b][c] = dp[a][b-1][c] + dp[a][b][c-1] - dp[a][b-1][c-1] + x;
    }
  }

  for(int i=1; i<=d; ++i) 
    for(int j=1; j<=h; ++j) 
      for(int k=1; k<=w; ++k)
        dp[i][j][k] += dp[i-1][j][k];

  int q; cin >> q;
  while(q --) {
    int d1, h1, w1; cin >> d1 >> h1 >> w1;
    int d2, h2, w2; cin >> d2 >> h2 >> w2;
    int res = dp[d2][h2][w2] - dp[d2][h1-1][w2] - dp[d2][h2][w1-1] - dp[d1-1][h2][w2];
    res += dp[d2][h1-1][w1-1] + dp[d1-1][h1-1][w2] + dp[d1-1][h2][w1-1];
    res -= dp[d1-1][h1-1][w1-1];
    cout << res << ln;
  }
  return 0;
}
