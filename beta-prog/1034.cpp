#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back
#define FOR(x,n) for(int x = 0; x < n; ++x)

const int N = 8;
int ar[N][N];
int col;

bool f(int r, int c, int k, int d) {
  if(r < 0 or c < 0 or r >= N or c >= N) return 0;

  if(d > 1 and ar[r][c] == col) return 1;
  if(d > 0 and (ar[r][c] != (col^1))) return 0;

  bool ok = 0;
  if(k == 0) ok = f(r+1, c+1, k, d+1);
  if(k == 1) ok = f(r+1, c, k, d+1);
  if(k == 2) ok = f(r+1, c-1, k, d+1);
  if(k == 3) ok = f(r, c+1, k, d+1);
  if(k == 4) ok = f(r, c-1, k, d+1);
  if(k == 5) ok = f(r-1, c+1, k, d+1);
  if(k == 6) ok = f(r-1, c, k, d+1);
  if(k == 7) ok = f(r-1, c-1, k, d+1);

  if(ok) ar[r][c] = col;

  return ok;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  int n; cin >> n;
  memset(ar, -1, sizeof ar);
  // 0 - white, 1 - black
  ar[3][3] = 0, ar[3][4] = 1;
  ar[4][3] = 1, ar[4][4] = 0;

  int t = 0;
  FOR(h, n){
    char a; int r; cin >> a >> r; r--;
    int c = a - 'a';
    lol:;
    col = (h+1 + t)%2;

    FOR(i, 8) f(r, c, i, 0);
    if(ar[r][c] == -1) {
      t ++;
      goto lol;
    }
  }

  FOR(i, N) {
    FOR(j, N) {
      int x = ar[i][j];
      if(x == -1) cout << ".";
      else if(x == 0) cout << "O";
      else cout << "X";
    }
    cout << ln;
  }

  return 0;
}
