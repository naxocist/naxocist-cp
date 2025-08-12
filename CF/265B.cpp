#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;

  int c = 0, res = 0;
  for(int i=0; i<n; ++i) {
    int x; cin >> x;
    res += abs(x-c) + 1;
    c = x;

    if(i != n-1) res ++;
  }

  cout << res;
  return 0;
}
