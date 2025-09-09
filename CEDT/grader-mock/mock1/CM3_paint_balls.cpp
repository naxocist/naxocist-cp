#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int n, m, k; cin >> n >> m >> k;
  char ar[n + 10][m + 10];
  for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) ar[i][j] = '-';

  while(k--) {
    char c; int r, x, y; cin >> c >> r >> x >> y;

    for(int i=0; i<n; ++i) {
      for(int j=0; j<m; ++j) {
        if(abs(x-i) + abs(y-j) <= r) ar[i][j] = c;
      }
    }
  }

  for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cout << ar[i][j] << " \n"[j == m-1];

  return 0;
}
