#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  char ar[n][m];
  for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin >> ar[i][j];

  for(int i=n-2; i>=0; --i) {
    for(int j=0; j<m; ++j) {
    	if(ar[i][j] == '*') ar[i+1][j] = '*';
    }
  }

  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) cout << ar[i][j] << ' ';
    cout << ln;
  }
  return 0;
}
