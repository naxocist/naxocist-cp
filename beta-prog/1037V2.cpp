#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

using T = tuple<int, int, int>;
const int N = 53, INF = 2e9;
char ar[N][N];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  
  queue<T> q;
  for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
      char &c = ar[i][j]; cin >> c;
    }
  }
  for(int i=0;i<n;++i)for(int j=0;j<m;++j)if(ar[i][j]=='*')q.emplace(i,j,0);
  for(int i=0;i<n;++i)for(int j=0;j<m;++j)if(ar[i][j]=='S')q.emplace(i,j,0);

  int t[]={1,0,-1,0,1};
  while(q.size()){
    auto [i,j,d]=q.front(); q.pop();
    for(int k=0;k<4;++k){
      int ni=i+t[k], nj=j+t[k+1];
      if(ni<0 or nj<0 or ni>=n or nj>=m or ar[ni][nj]=='X') continue;
      char c=ar[i][j],nxt=ar[ni][nj];
      if(c=='*' && nxt!='.') continue;
      if(c=='S' and (nxt=='S' or nxt=='*')) continue;
      if(nxt=='D')cout<<d+1,exit(0);
      ar[ni][nj]=ar[i][j];
      q.emplace(ni,nj,d+1);
    }
  }
  cout<<"KAKTUS";
  return 0;
}
