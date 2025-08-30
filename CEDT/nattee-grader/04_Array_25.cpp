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

  int mxl[n];
  for(int i=0; i<n; ++i) {
    mxl[i] = ar[i];
    if(i) mxl[i] = max(mxl[i], mxl[i-1]);
  }

  int res = 0, mxr = 0;
  for(int i=n-1; i>=0; --i) {
    mxr = max(mxr, ar[i]);
    res += max(min(mxl[i], mxr) - ar[i], 0);
  }

  cout << res;
  return 0;
}

