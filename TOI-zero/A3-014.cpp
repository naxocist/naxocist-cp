#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;

  int late = 0, t = n;
  while(t--) {
    int x; cin >> x;
    if(x > 18) late ++;
    else late --;
  }

  cout << n + max(0, late - 1);
  return 0;
}
