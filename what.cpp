#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  for(int i=0; i<n; ++i) {
    for(int j=0; j<2*n-1; ++j) {
      if(j >= n-i-1 and j-n < i) cout << "*";
      else cout << " ";
    }
    cout << '\n';
  }
  return 0;
}
