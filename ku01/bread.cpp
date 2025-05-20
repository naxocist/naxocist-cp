#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 1e3 + 3;
int x[N], y[N];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int w, h, n, m; cin >> w >> h >> n >> m;

  for(int i=1; i<=n; ++i) cin >> x[i]; x[n + 1] = w;
  for(int i=1; i<=m; ++i) cin >> y[i]; y[m + 1] = h;

  int mx, mx2; mx = mx2 = INT_MIN;
  for(int i=1; i<n+2; ++i) {
    int cw = x[i] - x[i-1]; 
    for(int j=1; j<m+2; ++j) {
    	int ch = y[j] - y[j-1];

    	int area = cw * ch;
    	if(area > mx) mx2 = mx, mx = area;
    	else if(area > mx2) mx2 = area;
    }
  }

  cout << mx << ' ' << mx2;
  return 0;
}
