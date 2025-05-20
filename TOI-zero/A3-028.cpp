#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m; cin >> n >> m;

  int ar[n][m] = {}, q;
  cin >> q;
  while(q--) {
  	int x, y; cin >> x >> y; ar[x][y] = -1;
  }

  for(int i=0; i<n; ++i) {
  	for(int j=0; j<m; ++j) {
  		if(ar[i][j] != -1) continue ;
  		for(int a=i-1; a<=i+1; ++a) {
  			for(int b=j-1; b<=j+1; ++b) {
  				if(a < 0 or b < 0 or a >= n or b >= m or ar[a][b] == -1) continue ;
  				ar[a][b] ++;
  			}
  		}
  	}
  }

  for(int i=0; i<n; ++i) {
  	for(int j=0; j<m; ++j) {
  		if(ar[i][j] == -1) cout << 'x';
  		else cout << ar[i][j];
  		cout << " ";
  	}
  	cout << ln;
  }
  return 0;
}
