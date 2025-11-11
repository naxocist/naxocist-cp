#include <bits/stdc++.h>
using namespace std;

int c[31][31];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k; cin >> n >> k;
  for(int i=0; i<=n; ++i) {
    for(int j=0; j<=i; ++j) {
      if(j == 0 or j == i) c[i][j] = 1;
      else c[i][j] = c[i-1][j] + c[i-1][j-1];
    }
  }

  cout << c[n][k];
  return 0;
}
