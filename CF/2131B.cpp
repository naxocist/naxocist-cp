#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;

    for(int i=0; i<n; ++i) {
      if(i&1^1) cout << -1;
      else {
        if(i == n-1) cout << 2;
        else cout << 3;
      }

      cout << ' ';
    }
    cout << ln;
  }
  return 0;
}