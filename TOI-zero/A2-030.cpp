#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n = 5;
  int ar[n][n];
  for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) cin >> ar[i][j]; 

  int a = -1, b = -1;
  for(int i=0; i<n; ++i) {
    int s = 0; for(int j=0; j<n; ++j) s += ar[i][j];
    if(s&1) a = i;
  }

  for(int i=0; i<n; ++i) {
    int s = 0; for(int j=0; j<n; ++j) s += ar[j][i];
    if(s&1) b = i;
  }

  if(a != -1 or b != -1) cout << a << ' ' << b;
  else cout << "-1 -1";
  return 0;
}
