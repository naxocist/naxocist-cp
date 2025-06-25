#include <bits/stdc++.h>
using namespace std;

const int N = 21;
double ar[N][N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;

  for(int i=0;i<n;++i)for(int j=0;j<n;++j) {
    cin >> ar[i][j]; ar[i][j]/=100;
  }

  vector<double> dp(1<<n, 0);
  dp[0] = 1;
  for(int i=1;i<(1<<n);++i){
    for(int j=0;j<n;++j){
      if(i&(1<<j)) dp[i]=max(dp[i],dp[i^(1<<j)]*ar[j][__builtin_popcount(i^(1<<j))]);
    }
  }

  cout << fixed << setprecision(12) << dp.back()*100;
  return 0;
}
