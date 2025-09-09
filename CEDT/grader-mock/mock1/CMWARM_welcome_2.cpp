#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  int ar[n + 1][m + 1];

  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j) cin >> ar[i][j];
  }
  
  int op;
  int a, b, k;
  while(cin >> op) {
    if(op == -1) break ;
    if(op == 1) {
      cin >> a >> k;
      for(int j=1; j<=m; ++j) ar[a][j] *= k;
    }

    if(op == 2) {
      cin >> a >> b >> k;
      for(int j=1; j<=m; ++j) ar[a][j] += ar[b][j]*k;
    }

    if(op == 3) {
      cin >> a >> b;
      for(int j=1; j<=m; ++j) swap(ar[a][j], ar[b][j]);
    }
  }

  for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) cout << ar[i][j] << " \n"[j == m];
  return 0;
}

