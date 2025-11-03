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
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=n; ++j) {
      if(n-i+1 == j or i == n) cout << "*";
      else cout << ".";
    }

    for(int j=1; j<=i-1; j++) {
      if(i-1 == j or i == n) cout << "*";
      else cout << ".";
    }
    cout << ln;
  }
  return 0;
}

