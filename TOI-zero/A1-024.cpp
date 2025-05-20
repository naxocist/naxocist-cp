#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int y, c; cin >> y >> c;

  if(y <= 1990) {
    if(c <= 1500) cout << 1250;
    else if(c <= 2000) cout << 1400;
    else cout << 2000;
  } 
  else if(y < 2000) {
    if(c <= 1500) cout << 1100;
    else if(c <= 2000) cout << 1300;
    else cout << 1700;
  } 
  else {
    if(c <= 1500) cout << 1000;
    else if(c <= 2000) cout << 1200;
    else cout << 1500;
  }
  return 0;
}
