#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, l; cin >> n >> l;
  vector<int> h(n), r(n); 
  for(auto &x : h) cin >> x;

  int mx = 0;
  for(int i=0; i<n; ++i) {
    r[i] = max(0, mx - h[i] + 1);
    mx = max(mx, h[i]);
  } 
  
  while(l--) {
    int x; cin >> x; x--;
    cout << r[x] << ln;
  }

  return 0;
}
