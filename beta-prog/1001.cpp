#include <bits/stdc++.h>
using namespace std;

char ar[20][20];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m; cin >> n >> m;

  int s[m];
  for (int i=0; i<m; ++i) s[i] = n;

  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      char c; cin >> c; ar[i][j] = c;

      if(c == 'O' and s[j] == n) s[j] = i;
    }
  }

  int t[m]; for(int i=0; i<m; ++i) cin >> t[i];


  for(int j=0; j<m; ++j) {
    if(s[j] == -1) continue ;
    for(int i=s[j]-1; t[j]-- and i >= 0; i--) {
      ar[i][j] = '#';
    }
  }

  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      cout << ar[i][j];
    }
    cout << '\n';
  }
  return 0;
}
