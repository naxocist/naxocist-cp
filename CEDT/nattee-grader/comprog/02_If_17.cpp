#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int x; cin >> x;

  if(x > 2000 or x < 0) cout << "Reject";
  else if(x > 1000) cout << 58;
  else if(x > 500) cout << 38;
  else if(x > 250) cout << 28;
  else if(x > 100) cout << 22;
  else cout << 18;
  return 0;
}
