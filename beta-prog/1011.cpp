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

    int rr = r, cc = o == 'L' ? c - 1 : c + 1;

    auto chk = [&](int a, int b) {
      return a >= 0 and a < n and b >= 0 and b < m;
    };


    if(!chk(r, c) or ar[r][c] == '#' or ar[r][c] == '-' or !chk(rr, cc) or ar[rr][cc] != '-'){
      sc -= 5;
      continue ;
    }

    swap(ar[r][c], ar[rr][cc]);

    auto apply = [&]() {
      for(int i=n-1; i>=0; --i) {
        for(int j=0; j<m; ++j) {
          char c = ar[i][j];

          if(c == '#' or c == '-') continue ;

          int k = i;
          while(k+1 < n and ar[k+1][j] == '-') swap(ar[k][j], ar[k+1][j]), k++;

          int tr[] = {0, 1, 0}, tc[] = {-1, 0, 1};
          bool ok = 0;
          for(int h=0; h<3; ++h) {
            int ii = k + tr[h], jj = j + tc[h];
            if(!chk(ii, jj)) continue ;
            if(ar[ii][jj] == c) sc += 5, ok = 1, ar[ii][jj] = '-';
          }

          if(ok) sc += 5, ar[k][j] = '-';
        }
      }
    };

    apply(); apply();
  }

  cout << sc << '\n';
  for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cout << ar[i][j] << " \n"[j == m-1];

  return 0;
}
