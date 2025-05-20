#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int n, m, q, x, y;

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cin >> n >> m;
  int ar[n][m] = {};
  cin >> q;
  while(q--) cin >> x >> y, ar[x][y] ++;

  int mx = 0;
  for(int i=0; i<n; ++i) {
  	for(int j=0; j<m; ++j) {
  		if(ar[i][j]) continue ;
  		int r = 0;
  		for(int h=i-1; h<=i+1; ++h) for(int k=j-1; k<=j+1; ++k) 
  			if(h >= 0 and h < n and k >= 0 and k < m) r += ar[h][k];
  		mx = max(mx, r);
  	}
  }

  cout << mx;
  return 0;
}
