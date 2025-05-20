#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 31;
bool ar[N][N], can[N][N];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  for(int i=1; i<=n; ++i) {
  	for(int j=1; j<=n; ++j) {
  		char c; cin >> c; ar[i][j] = c == '.';
  	}
  }

  int res = 1; can[n][n] = 1;
  for(int i=n; i>=1; --i) {
  	for(int j=n; j>=1; --j) {
  		if(i == n and j == n) continue ;
  		if(ar[i][j] and (can[i+1][j] or can[i][j+1])) can[i][j] = 1, res ++;
  	}
  }
  cout << res;
  return 0;
}
