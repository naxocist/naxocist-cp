
#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define pll pair<ll, ll>
#define all(x) begin(x), end(x)

void runcase() {
  int n; cin >> n;
  using T = tuple<ll, int, int>;
  vector<T> v;
  for(int i=0; i<n; ++i) {
    int x, y; cin >> x >> y;
    v.emplace_back((1ll*x*x+1ll*y*y)*((ll)1e5+1)+i, x, y) ;
  }
  sort(all(v));
  for(auto [a, b, c] : v) {
    cout << "(" << b << ", " << c << ")\n";
  }
  return ;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC; 
  while(TC--) runcase();
  return 0;
}
