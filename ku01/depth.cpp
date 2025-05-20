#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 1e5 + 4;
int prv[N], mx[N];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, q; cin >> n >> q;

  int dep = 0, cx = 0;
  mx[0] = INT_MAX;
  for(int i=0; i<n; ++i){
    int d, x; cin >> d >> x;
    dep += d;
    if(d == 1) prv[dep] = cx;
    cx += x;
    mx[dep] = max(mx[dep], cx - prv[dep]);
  }

  while(q--) {
    int x; cin >> x;
    int l = -1, r = n + 1;
    while(l + 1 < r) {
      int m = l + (r-l)/2;
      if(mx[m] >= x) l = m;
      else r = m;
    }

    cout << l << ln;
  }
  return 0;
}
