#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int g,d,bd;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  int ar[n][m];
  for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin >> ar[i][j];
  int a, b; cin >> a >> b;

  int mn = INT_MAX, mx = -INT_MAX;
  for(int i=0; i<n; ++i){
    for(int j=0; j<m; ++j) {
      int x = ar[i][j];
      mx = max(mx, x); mn = min(mn, x);
      if(x < a) g++;
      else if(x < b) d++;
      else bd++;
    }
  }


  printf("Good: %d\nDecent: %d\nBad: %d\nMin: %d\nMax: %d",g,d,bd,mn,mx);
  return 0;
}