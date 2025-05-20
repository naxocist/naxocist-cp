#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  char c; int x; cin >> c >> x;

  while(x--) {
    if(c == 'R') cout << "Red", c = 'G';
    else if(c == 'G') cout << "Green", c = 'B';
    else if(c == 'B') cout << "Blue", c = 'R';
    cout << ' ';
  }
  return 0;
}
