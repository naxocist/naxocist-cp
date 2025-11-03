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
  double ar[n];
  for(int i=0; i<n; ++i) cin >> ar[i];

  int res = 0;
  for(int i=1; i<n-1; ++i) {
    if(ar[i] > ar[i-1] && ar[i] > ar[i+1]) res ++;
  }

  cout << res;
  return 0;
}

