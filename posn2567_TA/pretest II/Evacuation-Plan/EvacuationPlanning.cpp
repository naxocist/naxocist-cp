#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back

const int N = 1e3 + 3, M = 1e5 + 3, W = 1e3 + 3;
int v1[M], w1[M], v2[M], w2[M], rat[M];

int main() {
  int n,m,w; cin>>n>>m>>w;

  for(int i=0;i<n;++i)cin>>v1[i];
  for(int i=0;i<n;++i)cin>>w1[i];
  for(int i=0;i<m;++i)cin>>v2[i];
  for(int i=0;i<m;++i)cin>>w2[i];

  vector<pair<int, int>> vec;
  for(int i=0;i<m;++i)vec.pb(rat[i]=v2[i]/w2[i],i);
  sort(vec.rbegin(), vec.rend());

  vector<int> dp(w+1);

  int d=0;
  for(int j=1; j<=w; ++j) {
    if(d >= m) {
      dp[j] = dp[j-1];
      continue;
    }
    int idx = vec[d].second;
    if(--w2[idx] == 0) d++;
    dp[j] = dp[j-1]+rat[idx];
  }

  for(int i=0; i<n; ++i) {
    for(int j=w; j>=0; --j) {
      if(j-w1[i]>=0) dp[j]=max(dp[j], dp[j-w1[i]] + v1[i]);
    }
  }

  cout << dp[w] << ".00";
  return 0;
}

