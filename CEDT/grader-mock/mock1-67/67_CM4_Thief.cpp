#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; int s; cin >> n >> s;

  int t = 0;
  vector<int> v(n); for(auto &x : v) cin >> x, t += x;

  for(int i=0; i<n; ++i) {
    for(int j=i+1; j<n; ++j) {
      if(t - v[i] - v[j] == s) {
        cout << i << ' ' << v[i] << ln;
        cout << j << ' ' << v[j] << ln;
        exit(0);
      }
    }
  }
  return 0;
}

