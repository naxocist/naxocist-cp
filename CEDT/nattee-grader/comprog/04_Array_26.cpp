#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  int ar[n*n];
  int zr = -1, k = 0;
  for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) {
    int x; cin >> x;
    if(x == 0) {
      zr = i;
      continue ;
    }
    ar[k++] = x;
  }

  int inv = 0;
  for(int i=0; i<k; ++i) {
    for(int j=0; j<i; ++j) inv += ar[j] > ar[i];
  }


  bool can = 0;
  if(n&1 && inv&1^1) can = 1;
  else if(n&1^1) {
    if((inv^zr)&1) can = 1;
  }

  cout << (can ? "YES" : "NO");

  return 0;
}

