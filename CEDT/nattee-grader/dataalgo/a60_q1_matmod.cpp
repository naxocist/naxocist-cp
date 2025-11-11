#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;
int n, K;

vvi mul(vvi &a, vvi &b) {
  vvi c(2, vi(2));
  for(int k=0; k<2; ++k) {
    for(int i=0; i<2; ++i) {
      for(int j=0; j<2; ++j) {
        c[i][j] += a[i][k]*b[k][j];
        c[i][j] %= K;
      }
    }
  }

  return c;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> K;

  int a, b, c, d; cin >> a >> b >> c >> d;
  vvi t = {{a, b}, {c, d}};
  vvi res = {{1, 0},{0, 1}};
  while(n) {
    if(n&1) res = mul(res, t);
    t = mul(t, t);
    n >>= 1;
  }

  cout << res[0][0] << ' ' << res[0][1] << ' ' << res[1][0] << ' ' << res[1][1];
  return 0;
}
