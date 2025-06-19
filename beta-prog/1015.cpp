#include <bits/stdc++.h>
using namespace std;

int ar[20][20], res, x, y;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) cin >> ar[i][j];

  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      auto f = [&](int r, int c) {
        int same = 0;
        if(ar[r][c] == ar[r+1][c]) same ++, x=1;
        if(ar[r][c] == ar[r-1][c]) same ++, x=-1;
        if(ar[r][c] == ar[r][c+1]) same ++, y=1;
        if(ar[r][c] == ar[r][c-1]) same ++, y=-1;

        return same;
      };

      if(f(i, j) == 2 and f(i+x, j) == 1 and f(i, j+y) == 1) res ++;
      x = 0, y = 0;
    }
  }

  cout << res;
  return 0;
}
