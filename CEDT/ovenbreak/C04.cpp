#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  for(int i=1; i<=n; ++i) {
    if(n % i) continue ;
    cout << i << ' ';
  }
  return 0;
}