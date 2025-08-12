#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

void solve() {
  int n, k; cin >> n >> k;
  int g = (n-1)/k + 1;

  vector<int> v(n);
  for(int i=0; i<n; ++i) v[i] = i + 1;

  for(int i=0; i<n; i+=k) {
    int l = i, r = min(n-1, i+k-1);
    int m = (l + r + 1)/2;

    reverse(begin(v)+l, begin(v)+m);
    reverse(begin(v)+m, begin(v)+r+1);
  }

  for(auto x : v) cout << x << ' '; cout << ln;
  cout << g << ln;
  for(int i=0; i<n; ++i) cout << i/k + 1 << ' ';
  cout << ln;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int T; cin >> T; while(T--) solve();
  return 0;
}
