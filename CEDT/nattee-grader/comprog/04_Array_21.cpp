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
  double a[n]; for(int i=0; i<n; ++i) cin >> a[i];

  for(int i=0; i<n; ++i) {
    double res = 0;
    for(int j=i; j>=0; --j) {
      res += a[j];
      if(j) res = 1/res;
    }
    cout << setprecision(10) << res << ln;
  }
  return 0;
}

