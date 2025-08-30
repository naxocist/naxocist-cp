#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n; int ar[n]; for(int i=0; i<n; ++i) cin >> ar[i];

  for(int i=0; i<n; ++i) cout << ar[i] << ' '; cout << ln;


  int tmp[n];
  for(int i=0; i<n; ++i) {
    int mx = -INT_MAX, idx = -1;
    for(int j=0; j<n-i; ++j) {
      if(ar[j] > mx) mx = ar[j], idx = j;
    }

    if(idx == n-i-1) continue ;
    if(idx) {
      for(int j=0; j<n; ++j) tmp[j] = ar[j];
      for(int j=0; j<=idx; ++j) ar[j] = tmp[idx-j];

      for(int j=0; j<n; ++j) cout << ar[j] << ' '; cout << ln;
    }

    for(int j=0; j<n; ++j) tmp[j] = ar[j];
    for(int j=0; j<=n-i-1; ++j) ar[j] = tmp[n-i-1-j];
    for(int j=0; j<n; ++j) cout << ar[j] << ' '; cout << ln;
  }

  return 0;
}

