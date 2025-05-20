#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  char a[n][m];
  for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin >> a[i][j];

  for(int i=0; i<n; ++i) {
  	for(int j=0; j<m; ++j) {
  		char b; cin >> b;
  		if(a[i][j] == '-') cout << b;
  		else cout << (b == '-' ? '+' : '*');
  	}
  	cout << ln;
  }
  return 0;
}
