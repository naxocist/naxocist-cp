#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 3;
int vis[N][N][N];
int cnt[N][N][N];


using T = tuple<int, int, int, int>;
int main() {
  int n, m, k; cin >> n >> m >> k;

  int prv = -1;
  bool ok = true;
  queue<T> q; 
  for(int i=0; i<k; ++i){
    int r, c; cin >> r >> c;
    q.emplace(r, c, i, 0);

    int parity=(r+c)%2;
    if(prv==-1) prv=parity;
    else if(prv!=parity) ok=false;
  }

  if(!ok) {
    cout << -1;
    return 0; 
  }

  while(q.size()) {
    auto [r, c, g, d] = q.front(); q.pop();
    if(vis[r][c][g]) continue ;
    cnt[r][c][d] += !vis[r][c][g];
    vis[r][c][g] = 1;

    if(cnt[r][c][d] == k) {
      cout << d; 
      break ;
    }

    for(auto x : {-1, -2, 1, 2}) {
      for(auto y : {-1, -2, 1, 2}) {
        if(abs(x) == abs(y)) continue ;
        int rr = r + x, cc = c + y;
        if(rr < 0 or rr >= n or cc < 0 or cc >= m) continue ;
        q.emplace(rr,cc,g,d+1);
      }
    }
  }

  return 0;
}

/*
0 0 0 1 0
0 0 1 0 0
0 0 0 0 0
0 0 0 0 0
0 1 0 0 0
*/
