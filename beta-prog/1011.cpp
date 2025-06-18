#include <bits/stdc++.h>
using namespace std;

const int N = 10;
char ar[N][N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m; cin >> n >> m;
  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      cin >> ar[i][j];
    }
  }

  int q; cin >> q;

  int sc = 0;
  while(q--) {
    int r, c; char o; cin >> r >> c >> o;

    int rr = r, cc = c;
    if(o == 'L') cc --;
    else cc ++;

    auto chk = [&](int a, int b) {
      return a >= 0 and a < n and b >= 0 and b < m;
    };

    if(!chk(r, c) or ar[r][c] == '#' or !chk(rr, cc) or ar[rr][cc] != '-'){
      sc -= 5;
      continue ;
    }

    while(rr < n and ar[rr][cc] == '-') rr ++;
    rr --;

    bool ok = false;
    int tr = -1, tc = -1;
    if(rr+1 < n and ar[rr+1][cc] == ar[r][c]) ok=1, sc+=5, ar[rr+1][cc]='-';
    if(cc-1 >= 0 and ar[rr][cc-1] == ar[r][c]) ok=1, sc+=5, ar[rr][cc-1]='-';
    if(cc+1 < m and ar[rr][cc+1] == ar[r][c]) ok=1, sc+=5, ar[rr][cc+1]='-';

    if(ok) {
      ar[r][c] = '-';
      sc += 5;
    }else {
      ar[rr][cc] = ar[r][c];
    }

    for(int i=n-1; i>=0; --i) {
      for(int j=0; j<m; ++j) {
        if(ar[i][j] == '#' or ar[i][j] == '-') continue ;
        int k = i;
        while(k < n and (ar[k][j] == '-' or ar[k][j] == ar[i][j])) k ++;
        k --;
        char t = ar[i][j]; ar[i][j] = '-';
        ar[k][j] = t;
      }
    }
  }

  cout << sc << '\n';
  for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cout << ar[i][j] << " \n"[j == m-1];

  return 0;
}
